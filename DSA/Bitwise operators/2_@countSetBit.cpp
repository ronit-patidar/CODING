// setbits are 1 & 0s are offbits,unsetbits
#include<iostream>
#include<string>
using namespace std;
// in bulid function 
int count_set_bit(int n){
    return __builtin_popcount(n);
}
int count_set_bit2(int n){
    int count=0;
    while(n>0){
        count++;
        n=(n & (n-1)); // imp 
    }
    return count;
}

int main(){
    cout<<count_set_bit(29)<<endl;
    cout<<count_set_bit2(29)<<endl;
}