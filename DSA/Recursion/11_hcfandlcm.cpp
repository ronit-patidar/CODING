#include<iostream>
using namespace std;
// hcf(a,b) <= min(a,b)
// eg: (24,60) -> 24 to 1 ki range me lie karega 
//  why loop from end ?
//  because we have to find hcf (highest common diviser)
int hcf(int a,int b){   //tc =O(min(a,b))
    for(int i=min(a,b);i>=2;i--){
        if(a%i==0 && b%i==0){
            return i;
            break;
        }
    }
    return 1; 
    // if hcf not found then return 1 (because 1 sabka hcf hota he h)
}
int lcm(int a, int b) { // tc =O(min(a,b))
    for (int i = max(a, b); i <= a * b; i++) {
        if (i % a == 0 && i % b == 0) {
            return i;
        }
    }
    return a * b;
}
// euclids 
int gcd(int a,int b){ // O(min(a,b))
    //  work for a<b & a>b
    if(a==0) return b;
    return gcd(b%a,a);
}
int lcmrec(int a,int b){
    return (a*b)/gcd(a,b);
}
int main (){
    cout<<"HCF is "<<hcf(24,60)<<endl;
    cout<<"HCF is "<<gcd(24,60)<<endl;
    cout<<"LCM is "<<lcmrec(24,60)<<endl;
    cout<<"LCM is "<<lcm(24,60)<<endl;
}