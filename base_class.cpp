#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor\n"; }
    virtual ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived constructor\n"; }
    ~Derived() { cout << "Derived destructor\n"; }
};

int main() {
    Base* obj = new Derived();
    delete obj;
    cout<<"------------------"<<endl;
    Base* obj2=new Base();
    delete obj2;
    cout<<"------------------"<<endl;
    Derived* obj3=new Derived();
    delete obj3;
}



/*
You often don’t know at compile time which derived type you will create. For example:

Base* obj;
if(choice == 1) obj = new Derived1();
else obj = new Derived2();


Now you can store either Derived1 or Derived2 in the same Base*.
Later, when you do delete obj;, you need a virtual destructor to ensure the correct Derived destructor runs.
*/