#include<iostream>
using namespace std;
int main(){
    int a,b; 
    cout<<"Enter two number :"; 
    cin>>a; 
    cin>>b;
    // int temp = a;//temp=a
    // a=b;
    // b=temp;
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<a<<endl<<b;
}