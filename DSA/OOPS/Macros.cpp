#include<iostream>
using namespace std;
//MACROS
#define PI 3.14159465

 float areaOFcircle(float r){
    return PI*r*r;
}

 float perimeterOFcircle(float r){
    return 2*PI*r;
}
int main (){
    cout<<areaOFcircle(10);
    cout<<endl;
    cout<<perimeterOFcircle(10);
}