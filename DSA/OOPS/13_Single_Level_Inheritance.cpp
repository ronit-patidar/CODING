#include<iostream>
using namespace std;
class Car{
    public:
    string name;
    int weight;
    int age;
    void speedup(){
        cout<<"Speeding up";
    }
    void brake(){
        cout<<"Brake";
    }
};
class Rapid : public Car{

};
int main(){
    Rapid r1;
    r1.speedup();
    return 0;
}