#include<iostream>
using namespace std;
class Animal{
    public:
        Animal(){
            cout<<"Animal constructor"<<endl;
        }
        void speak(){
            cout<<"Speaking"<<endl;
        }
};
class Dog : public Animal{
    public:
        Dog(){
            cout<<"Dog constructor"<<endl;
        }
        // Function overriding
         void speak(){
            cout<<"Barking"<<endl;
        }
};
int main(){
     // MCQS            

    // constructor called objectwise, jo ki right side hai

    // parent constructor called
    Animal *a = new Animal(); 
    cout<<endl;

    // Dog *d=new Dog(); wrong way , compiler will give error

    // parent constructor called then child constructor called
    Dog *d=(Dog*) new Dog(); // explicit typecast, 
    cout<<endl;

    // parent constructor called then child constructor called
    Animal *b = new Dog();
    cout<<endl;

    Dog *c=(Dog*) new Animal();
    cout<<endl;


    // // DOG ka pointer and object dog ka hai
    // Dog *b = new Dog(); 
    // cout<<endl;
    // // pointer animal class ka hai, and object dog ka hai
    // // UPPCASTING
    // Animal *c = new Dog(); // Animal constructor then dog constructor as after new Dog is written
    // cout<<endl;
    // // Downcasting
    // // child class ka pointer and parent class ka object
    // Dog *d = (Dog*) new Animal();
    // cout<<endl;
    return 0;
    // wihtout use of virual keyword, pointer method/function will called
    // with use of virtual keyword, object method/function will called
}