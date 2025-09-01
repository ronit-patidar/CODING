#include<iostream>
using namespace std;
class abc{
    public:
     int x,y;
     abc(): x(0),y(0) {}
    static void print()  {      //kisi instance ka nahi hoga
          // cout<<x<<" "<<y<<endl;// not acceable cause koi instance pass nahi ho raha h
          // can acces only static varibles
          // no this pointer accesable
          cout<<"I am in static print"<<endl;
    }
};
int main(){
    abc obj1;
    abc obj2;
    abc::print();
    abc::print();
    abc::print();
}