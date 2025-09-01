// https://www.naukri.com/code360/problems/check-armstrong_589

#include<iostream>
using namespace std;
// 153 is Armstrong 
// cube of 1 + cube of 5 + cube of 3 = 153
void checkarmstrong(int n){ // O(d) or (log10 n)
    int original=n;
    int sum=0;
    while(n > 0){
        int digit = (n % 10) ;
        sum += digit*digit*digit;
        n /= 10 ;
    }
    if(sum==original) cout<<original<<" is armstrong number. ";
    else cout<<original<<" is not a armstrong number.";
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    checkarmstrong(n);
}