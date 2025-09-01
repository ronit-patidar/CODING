#include<iostream>
using namespace std;
class Animal{
       int age;
       public:
       ~Animal(){
        cout<<"destructor is called "<<endl;
       }
};
int main(){
    Animal suresh;
    Animal* ramesh = new Animal;
    delete ramesh;
}