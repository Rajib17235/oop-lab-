#include<bits/stdc++.h>
using namespace std;

float arr[20];

class Person
{
public:
    string Name;
    int Age;

    Person(string name, int age);
};

Person::Person(string name, int age)
{
    Name=name;
    Age=age;
}

class Student:public Person
{
private:
    float CGPA;
    int ACM_Solve;

public:
	Student(string n, int a, float g, int s) : Person(n,a), CGPA(g), ACM_Solve(s) {}
	void showStudent();

	int checkCGPA(float cgpa)
    {
        if(CGPA==cgpa && ACM_Solve>=100)
            return 1;

        else return 0;
    }

    float accessCGPA()
    {
        return CGPA;
    }
};

void Student::showStudent()
{
    cout << setw(10) << Name << setw(13) <<  CGPA << setw(13) << ACM_Solve << endl << endl;
}

int main()
{
    int i,j;
    Student *performance[10]=
    {
        new Student("Nayon",20,3.66,60),
        new Student("Saiful",23,3.77,280),
        new Student("Rakibul",21,3.35,250),
        new Student("Mehedi",20,3.26,210),
        new Student("Rajib",23,3.18,100),
        new Student("Fahim",21,3.21,120),
        new Student("Asik",22,3.53,130),
        new Student("Rinky",22,3.27,99)
    };

    float temp;
    int counter=0;
    float maximum;

    for(i=7;i>=0;i--)
    {
        arr[i]=performance[i]->accessCGPA();
        for(j=0;j<7-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j] = temp ;
            }
        }
    }

    cout << "TOP 5 students on the Honour Board are:" << endl << endl;
    cout << setw(10) << "Student Name"  << setw(10) << "CGPA" << setw(17) << "ACM Solve" << endl  ;
    cout << setw(10) << "____________"  << setw(10) << "___" << setw(17) << "_________" << endl << endl ;

    for(i=7;i>=0;i--)
    {
        maximum=arr[i];

        for(j=0;j<7;j++)
        {
            if(performance[j]->checkCGPA(maximum)==1)
            {
                counter++;
                performance[j]->showStudent();
            }

            if(counter==5) break;
        }
    }
    return 0;
}
