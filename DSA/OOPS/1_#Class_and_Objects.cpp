#include<iostream>
using namespace std;
class Animal{ // creation of class 
    // Data Members and Member Function
    // Access modifier
    private: // by default everything is marked private
    int weight;

    public:
    int age;
    string name;
    // Data functions
    void eat(){
        cout<<"I am eating";
    }
    void sleep(){
        cout<<"I am sleeping";
    }
    // void setWeight(int w){
    //     weight = w;
    // }

    // this keyword
    // getter and Setters are used to access private members 
    void setWeight(int weight){
        this->weight = weight; // Differentiate 
        // this->weight (member variable) = weight (parameter)
    }
    // Getter
    void getWeight(){
        cout<<weight;
    }
};
int main(){
    // Object creation
    Animal ramesh;
    // Accessing or modifing property of object
    ramesh.age = 12;
    ramesh.name = "lion";
    cout<<ramesh.age<<" "<<ramesh.name<<endl; // 12 lion
    // Calling member functions
    ramesh.eat(); // I am eating
    cout<<endl;
    // Getter and setter use
    ramesh.setWeight(101);
    ramesh.getWeight();
    cout<<endl;
    // Dyanamic Memory allocation
    Animal *suresh = new Animal;
    // 1st way (dot operator)
    (*suresh).age = 15;
    (*suresh).name = "billi";
    // 2nd way (Arrow operator)
    suresh->name = "sher";
    suresh->age = 16;
    suresh->eat();
    cout<<endl;
    cout<<suresh->name<<" "<<suresh->age;
    return 0;
}