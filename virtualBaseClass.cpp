#include<bits/stdc++.h>
using namespace std;
class A{
public:    
A()
{
    cout<<"a constructor"<<endl;
}
void display()
{
    cout<<"a display"<<endl;
}
~A()
{
    cout<<"a destructor"<<endl;
}
};

class B:virtual public A{
public:
B()
{
    cout<<"b constructor"<<endl;
}
~B()
{
    cout<<"b destructor"<<endl;
}
};

class C:virtual public A{
public:
C()
{
    cout<<"c constructor"<<endl;
}
~C()
{
    cout<<"c destructor"<<endl;
}
};

class D:public B,public C{
public:
D()
{
    cout<<"d constructor"<<endl;
}
~D()
{
    cout<<"d destructor"<<endl;
}
};

int main()
{
D d;
d.display();
return 0;
}