// https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

#include<iostream>
#include<cmath>
using namespace std;

//  Sieve of Eratosthenes
// checking prime upto root n 
// O(root n) , O(1)
bool checkPrime(int n){ 
    if(n==1) return false ;
    for(int i=2;i<=sqrt(n);i++){ // or i*i<=n
        if(n%i==0) return false ;
    }
    return true;
}

// O(root n) , O(1)
void factors(int n){ 
    cout<<"Factors are : ";
    for(int i=1;i<=sqrt(n);i++){ 
        if(n%i==0) {
            cout<<i<<" ";
            if(i != (n/i)) cout<<(n/i)<<" ";
        }
    }
}

 // O(n),O(1)
bool brutePrime(int n){
    if(n==1) return false;
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    cout<<brutePrime(n)<<endl;
    cout<<checkPrime(n)<<endl;
    factors(n);
}