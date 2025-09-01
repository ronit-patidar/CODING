#include<iostream>
#include<stack>
using namespace std ;
// Step 1: 5 ÷ 2 = 2 (quotient) and 1 (remainder)
// Step 2: 2 ÷ 2 = 1 (quotient) and 0 (remainder)
// Step 3: 1 ÷ 2 = 0 (quotient) and 1 (remainder)
// Remainders: 1 0 1
void fun(int n){
    stack<int> s;
    while (n > 0){
    s.push(n%2);
    n = n/2;
 }
 while (!s.empty()){
    cout<<s.top();
    s.pop();
 }
}
int main(){
    int n=5;
    fun(n);
}