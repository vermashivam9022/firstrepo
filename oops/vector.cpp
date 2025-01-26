#include<bits/stdc++.h>
using namespace std;


class Cricketer{
    public:
    string name;
    int run;
    float avg;

    Cricketer()
    {
        name = "";
        run = 0;
        avg = 0.0;
    }

    Cricketer(string n, int r,float a)
    {
        this->name = n;
        this->run = r;
        this->avg = a;
    }

    void print()
    {
        cout << "Name: " << name <<  " Runs: " << run << " Average: " << avg << endl;
    }
};

void print(Cricketer c)
{
    cout << "Name: " << c.name <<  " Runs: " << c.run << " Average: " << c.avg << endl;
    c.name="sachin";
  
}
void print2(Cricketer& c)
{
    cout << "Name: " << c.name <<  " Runs: " << c.run << " Average: " << c.avg << endl;
    c.name="sachin";
  
}

void print3(Cricketer* c)
{
    cout << "Name: " << (*c).name <<  " Runs: " << (*c).run << " Average: " << (*c).avg << endl;

}
void print4(Cricketer* c)
{
    cout << "Name: " << c->name <<  " Runs: " <<c->run << " Average: " << c->avg << endl;

}
int main()
{
    Cricketer c1("Virat kohli",25000,55.5);
    Cricketer c2("Rohit sharma",18000,60.0);

    
    // print(c1);
    // c1.print();

    // print2(c2);
    // c2.print();

    // print3(&c1);
    // print4(&c2);

    int x=10;
    int *p=&x;
    cout<< *p << endl;

   
    int *q= new int(20);
    cout<< *q << endl;

    Cricketer *ptr=new Cricketer(c1);
    cout<< ptr->name << ":"<< ptr->run <<endl;


    Cricketer *ptr2=new Cricketer("rohit",18000,52.3);
    cout<< ptr2->name << ":"<< ptr2->run <<endl;


    return 0;
}