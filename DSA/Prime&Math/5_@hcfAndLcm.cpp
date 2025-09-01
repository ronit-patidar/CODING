// https://www.geeksforgeeks.org/program-to-find-gcd-or-hcf-of-two-numbers/

#include<iostream>
using namespace std;
// hcf is known as gcd
// if a=0 and b then b is gcd
// if a and b=0 then a is gcd
int gcd(int a,int b){
    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) return b;
    return a;
}
int gcdrec1(int a,int b){
    // assume a>b
    if(b==0) return a;
    return gcdrec1(b,a%b);
}
int lcm(int a,int b){
    return (a*b)/(gcd(a,b));
}
int main(){
    int a,b;
    cout<<"Enter two number : ";
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    cout<<gcdrec1(a,b)<<endl;
    cout<<lcm(a,b)<<endl;
}