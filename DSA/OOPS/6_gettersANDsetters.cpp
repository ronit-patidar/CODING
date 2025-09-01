#include<iostream>
using namespace std;
class Animal{
     int weight;
     public:
     void setWeight(int w){//setter
        weight=w;
     }
     void getWeight(){//gettte
        cout<<weight;
     }
};
int main(){
   Animal ramesh;
   ramesh.setWeight(10);
   ramesh.getWeight();
}