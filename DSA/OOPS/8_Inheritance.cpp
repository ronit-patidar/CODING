#include<iostream>
using namespace std;
class Animal{
    public:
    int age;
    int weight;
    void eat(){
        cout<<"Eating"<<endl;
    }
};
class dog:public Animal{

};    
int main(){
    dog d1;
    d1.eat();
}



















