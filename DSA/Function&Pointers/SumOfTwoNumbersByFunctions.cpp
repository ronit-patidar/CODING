#include<iostream>
using namespace std;
int main(){
    int x1;
    cout<<"Enter the first number : ";
    cin>>x1;
    int* p1 = &x1;
    int x2;
    cout<<"Enter the second number : ";
    cin>>x2;
    int* p2 = &x2;
    int sum=*p1+*p2;
    cout<<sum;
}