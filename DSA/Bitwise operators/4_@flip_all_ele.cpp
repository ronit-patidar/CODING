// do yourself
#include<iostream>
using namespace std;
// flip all its bits 
int flip(int n){
    n = n | (n>>1);  
    n = n | (n>>2);  
    n = n | (n>>4);   
    n = n | (n>>8);   
    n = n | (n>>16);   
    return n;
}
string decimal_to_binary(int num){
    string result="";
    while(num>0){
        if(num%2==0) {// even
            result='0'+result;// prepend
        }
        else {// odd
            result='1'+result;// prepend
        }
        //num = num / 2;
        num=num>>1;// divide by 2
    }
    return result;
}
int main(){
    // method 1
    int n=406;              // 110010110
    int m = flip(n);       //111111111
    int result =  n ^ m;  // 001101001
    cout<<"Expected : 110010110 -> "<<decimal_to_binary(n)<<endl;
    cout<<"Expected : 111111111 -> "<<decimal_to_binary(m)<<endl;
    cout<<"Expected : 001101001 -> "<<decimal_to_binary(result)<<endl;
}