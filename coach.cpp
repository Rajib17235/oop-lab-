#include<bits/stdc++.h>

using namespace std;

class Date
{
public:
    int day,month,year;
    Date() {};
    Date(int d,int m,int y)
    {
        day=d;
        month=m;
        year=y;
    }

};

class Person
{
public:
    string name;
    Date d1;
    Person() {};
    Person(string n)
    {
        name=n;
    }
    Person(string n,Date *d)
    {
        name=n;
        d1=*d;
    }
};

    class Department
    {
    public:
        string dept_name;
        Department() {};
        Department(string n)
        {
            dept_name=n;
        }
    };

    class Student : public Person
    {
    public:
        int id,ACM,prob_solve;
        Department d;
        Student() {};
        Student(string n,Date *d2,Department *dp,int dd,int acm,int solve) : Person(n,d2)
        {
            id=dd;
            d=*dp;
            ACM=acm;
            prob_solve=solve;
        }
        View_Student_Info()
        {
            cout<<"Student name: "<<name<<endl;
            cout<<"Department: "<<d.dept_name<<endl;
            cout<<"Students Birthday: "<<d1.day<<"-"<<d1.month<<"-"<<d1.year<<endl;
        }
    };

    class Faculty : public Person
    {
    public:
        Student student;
        string designation;
        Department department;
        Faculty() {};
        Faculty(string d,string n,Department *department):Person(d)
        {
            designation=n;
            this->department=*department;
        }
        View_Faculty()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Department: "<<department.dept_name<<endl;
            cout<<"Designation: "<<designation<<endl;
        }
        int select_coach(Student *student)
        {
            //student=*student;
            if(student->ACM>=3&&student->prob_solve>300)
                return 1;
            else
                return 0;
        }
    };

    int main()
    {
        Department *department[5]=
        {
            new Department("CSE"),
            new Department("CSE"),
            new Department("CSE"),
            new Department("CSE"),
            new Department("CSE"),
        };

        Date *date[4]=
        {
            new Date(29,07,1991),
            new Date(10,05,1993),
            new Date(17,11,1988),
            new Date(22,02,1985)
        };
        Student *student[3]=
        {
            new Student("Konik",date[0],department[0],1010,3,316),
            new Student("Atik",date[1],department[1],1020,4,260),
            new Student("Nahid",date[2],department[2],1018,6,207)
        };
        Faculty *faculty[2]=
        {
            new Faculty("Kamal Hossain Chowdhury","Assistant Professor",department[3]),
            new Faculty("Mahmudul Hasan","Assistant Professor",department[4])
        };
        cout<<"The Details Of Faculty Member: "<<endl<<endl;
        for(int i=0; i<2; i++){
            faculty[i]->View_Faculty();
            cout<<endl;
        }
        cout<<endl<<endl;
        cout<<"The Details Of Students: "<<endl<<endl;
        for(int i=0; i<3; i++){
            student[i]->View_Student_Info();
            cout<<endl;
        }
        int x;
        cout<<endl<<endl;
        for(int i=0;i<3;i++)
        {
           x=faculty[i]->select_coach(student[i]);
           if(x==1)
           {
               cout<<"The Student Can be Selected as A Coach.."<<endl;
               cout<<"The Details Of The Students: "<<endl;
               student[i]->View_Student_Info();
               cout<<endl<<endl;
           }
           else
           {
               cout<<"The Student Can not be Selected as A Coach."<<endl;
               cout<<"The Details Of The Students: "<<endl;
               student[i]->View_Student_Info();
               cout<<endl<<endl;
           }
        }
        return 0;
    }

