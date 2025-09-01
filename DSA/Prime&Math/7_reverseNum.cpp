#include <iostream>
using namespace std;
void reverseNum(int n){
    int revNum=0;
    while(n != 0){
        int digit=n%10;
        revNum = (revNum*10) + digit;
        n=n/10;        
    }
    cout<<revNum;
}
int main() {
    // int n=4537;
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    reverseNum(n);
}
