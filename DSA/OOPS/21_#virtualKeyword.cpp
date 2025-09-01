#include<iostream>
using namespace std;
class Animal{
    public:
    // virtual : runtime par decide ho ke konsa funtion call ho then use virtual keyword , object function/method call hoga
        virtual  void speak(){
            cout<<"Speaking"<<endl;
        }
};
class Dog : public Animal{
    public:
        // Function overriding
         void speak(){
            cout<<"Barking"<<endl;
        }
};
int main(){
    // MCQS

    // jiska pointer hai uska method/function call hoga
    // Animal *a = new Animal(); 
    // a->speak();
    // cout<<endl;

    // Dog *b = new Dog(); 
    // b->speak();
    // cout<<endl;

    // //pointer animal class ka hai, and object dog ka hai
    // // wihtout use of virual keyword, pointer method/function will called
    // // with use of virtual keyword, object method/function will called
    // //UPPCASTING
    // Animal *a = new Dog(); // Animal constructor then dog constructor as after new Dog is written
    // a->speak(); // hamesha parent ka funtion call hota h
    // cout<<endl;

    Dog *b =(Dog*) new Animal(); // explicit typecast
    b->speak();
    
    return 0;
}