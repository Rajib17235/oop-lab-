#include<bits/stdc++.h>
#include<string>
#include <sstream>
using namespace std;
class Member
{
    protected :
    string name;
    int deposit;
    int bill;
    string message;
    public :
        Member() { }
        Member(string n,int d)
        {
            name=n;
            deposit=d;
        }
} ;
class date
{
    protected:
    string date[3];
    int morning[3],noon[3],night[3];
};
class Mealinfo : public date
{
    protected:
    int meal_count()
        {
            int a=0;
            for(int i=0;i<3;i++)
            {
                a+=morning[i]+noon[i]+night[i];
            }
            return a;
        }
};
class Mess_Owner : public Member,Mealinfo
{
    int totalcost;
    float mealrate;
public :
   Mess_Owner() { }
  Mess_Owner(string n,int d) : Member(n,d) { }
   void   get_meal(int FirstDayMorning,int FirstDayNoon,int FirstDayNight,int SecDayMorning,int SecDayNoon,int SecDayNight,int ThirdDayMorning,int ThirdDayNoon,int ThirdDayNight)
    {
            morning[0]=FirstDayMorning;         noon[0]=FirstDayNoon;           night[0]=FirstDayNight;
            morning[1]=SecDayMorning;         noon[1]=SecDayNoon;           night[1]=SecDayNight;
            morning[2]=ThirdDayMorning;         noon[2]=ThirdDayNoon;           night[2]=ThirdDayNight;
    }

   void get_totalcost(int k) { totalcost=k; }
   int access_meal() { return meal_count(); }
   float get_mealrate(int sum) { return (totalcost/sum) ;}
   void passmessage(float m)
   {
       int a;
       message=" " + name ;
       if(deposit<1000)
        message=message +  "   You don't have enough deposit. Your meal will be closed if you don't increase your deposit .\n\n" ;
       a=meal_count();
       bill=(a*m) - deposit ;
       string String = static_cast<ostringstream*>( &(ostringstream() << bill) )->str();

       if(bill>0)
        message=message+ " you have to pay  " + String +" tk more. \n";
        else {bill=-bill;
         string String = static_cast<ostringstream*>( &(ostringstream() << bill) )->str();
          message=message+ " you will get " + String +" tk in return . \n";
        }
   }
   void show_message()
   {
       cout << message << endl;
   }
};
int main()
{
    Mess_Owner *memberinfo[5]={
        new Mess_Owner("Sajid",1300),
        new Mess_Owner("Reon",1100),
        new Mess_Owner("Sumon",700),
        new Mess_Owner("Helal",800),
            };
    memberinfo[0]->get_meal(1,0,1,0,1,1,0,1,1 );
    memberinfo[1]->get_meal(1,0,1,0,1,1,0,1,0 );
    memberinfo[2]->get_meal(1,0,1,0,1,0,1,0,1 );
    memberinfo[3]->get_meal(1,0,1,0,1,1,0,1,1 );

    Mess_Owner Shakil;
    Shakil.get_totalcost(900);
    int sum=0;
    float  mealrate;
    for(int i=0;i<4;i++)
    {
        sum+= memberinfo[i]->access_meal();
    }
    mealrate=Shakil.get_mealrate(sum);
    for(int i=0;i<4;i++)
       {
           memberinfo[i]->passmessage(mealrate);
           memberinfo[i]->show_message();
       }
  return 0;
}
