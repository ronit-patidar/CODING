#include<iostream>
using namespace std;
// function call itself is called recursion.
// n! = n * (n-1)!
int fact(int n){
    if(n==1 || n==0) return 1; // base call
    return n*fact(n-1);       // recursive call
}
int main(){
    cout<<fact(5);
}