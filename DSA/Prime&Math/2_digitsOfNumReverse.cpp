#include<iostream>
using namespace std;
// display digits of number in reverse order 
void digitsRev(int num){ // O(d) or O(log10 3) where d is no digits
    if(num<=0) cout<<"Invalid";
    while(num>0){
        cout<< num % 10;
        num /= 10;
    }
}
int main(){
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    digitsRev(n);
}