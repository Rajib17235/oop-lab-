#include<bits/stdc++.h>
using namespace std;
class Person
{

    string name;
    string dob;
    long int mobile_number;
public:
    Person() {};
    Person(string name,string dob,long int mobile_number)
    {
        this->name=name;
        this->dob=dob;
        this-> mobile_number=mobile_number;
    }
    void display_person()
    {
        cout<<"Person's details:"<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Date of birth:"<<dob<<endl;
        cout<<"Mobile number:"<<mobile_number<<endl;
    }
};
class Driver:public Person
{

    string direction;
public:
    friend class Uber;
    Driver() {};
    Driver(string name,string destination,long int mobile_number, string direction):Person(name,destination,mobile_number)
    {
        this->direction=direction;
    }

};
class Uber
{
public:
    string location;
    void contact_with_driver(string location,Driver driver_object)
    {
        if(location==driver_object.direction)
        {
            cout<<"Person's occupation is driving."<<endl;
            driver_object.display_person();
            cout<<"The driver is booked.";
        }

    }
};
class Customer:public Person
{

public:
    friend class Uber;
    string destination;
    Customer() {};
    Customer(string name,string dob,long int mobile_number,string destination):Person(name,dob,mobile_number)
    {
        this->destination=destination;
    }
    void display_customer()
    {
        cout<<"Customer's destination is:"<<destination<<endl;
        display_person();
    }
    void contact_with_uber(Uber &uber,Driver &driver)
    {
        uber.contact_with_driver(destination,driver);

    }
};

int main()
{
    Uber uber1;
    ifstream file2;
    string name,dob,phone,direction,destination;
    file2.open("e:/input.csv");
    getline(file2,name,',');
    getline(file2,dob,',');
    getline(file2,phone,',');
    getline(file2,destination,'\n');
    int phone1,phone2;
    stringstream g(phone);
    g >> phone1;
    Customer customer1=Customer(name,dob,phone1,destination);
    file2.close();
    ifstream file3;
    Driver driver[3];
    int i=0;
    file3.open("e:/driver.csv");
    while(file3.good())
    {
        getline(file3,name,',');
        getline(file3,dob,',');
        getline(file3,phone,',');
        getline(file3,direction,'\n');
        stringstream ge(phone);
        ge >> phone2;
        driver[i]=Driver(name,dob,phone2,direction);
        customer1.contact_with_uber(uber1,driver[i]);
        i++;

    }
    file3.close();
    cout<<"\n\n";
    customer1.display_customer();
    cout<<"\n\n";
    return 0;
}

