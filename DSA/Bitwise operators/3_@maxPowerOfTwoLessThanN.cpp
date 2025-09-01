// n se just badi power nikalne k liye n se multiply kar do

#include<iostream>
#include<string>
using namespace std;
// dry run with example

// n = 24 (11000)

// n = n | (n>>1);   
// 11000 |  01100   = 11100 

// n = n | (n>>2);  
// 11100 | 00111   = 11111

// n = n | (n>>4);  
// n = n | (n>>8);  
// n = n | (n>>16);

// 11111 -> 31
// 2^5 - 1  = 31
// 2^4 = 32/2 (n+1>>1)



int max_power_less_than_n(int n){
    // set bit , upto 32 bit number 
    n = n | (n>>1);  // if no is of 8 bit     
    n = n | (n>>2);  // if no is of 8 bit     
    n = n | (n>>4);  // if no is of 8 bit     
    n = n | (n>>8);  // if no is of 16 bit    
    n = n | (n>>16); // if no is of 32 bit     
    // return n+1 / 2
    return (n+1)>>1;
}
int max_power_greater_than_n(int n){
    n = n | (n>>1);     
    n = n | (n>>2);
    n = n | (n>>4);
    n = n | (n>>8);
    n = n | (n>>16);
    return 2*((n+1)>>1);
}

int main(){ 
    // method 1
    // thinkable problem
    // brain kerniglen's algorithm
    int x=24;
    int temp;
    while(x!=0){
        temp=x;
        x=x&(x-1);
    }
    cout<<"max power just  less than n : "<<temp<<endl; 
    cout<<"max power just geater than n : "<<2*temp<<endl; 
    // second method
    int y=24;
    cout<<max_power_less_than_n(y)<<endl;
    cout<<max_power_greater_than_n(y);
}