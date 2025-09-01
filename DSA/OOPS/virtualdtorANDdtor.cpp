#include<iostream>
using namespace std;
class Base{
    public:
    // virtual ctor cant be made
    Base(){
        cout<<"Base ctor"<<endl;
    }
    virtual ~Base(){
        cout<<"Base dtor"<<endl;
    }
};
class Derived:public Base{
    int *a;
    public:
    Derived(){
        a=new int[1000];
        cout<<"Derived ctor"<<endl;
    }
    ~Derived(){
        delete[] a;
        cout<<"Derived dtor"<<endl;
    }
};
int main(){
    Base *b = new Derived();
    delete b;
    return 0;

}