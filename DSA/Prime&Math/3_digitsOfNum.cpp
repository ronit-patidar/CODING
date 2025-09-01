#include<iostream>
#include<vector>
using namespace std;
// display digits of number in original order 
void digits(int n){ // // O(d) or O(log10 3) , O(d) d is no of digits
    vector<int> v;
    while(n > 0){
        int num = 0;
        num = n % 10;
        v.push_back(num);
        n /= 10 ;
    }
    for(int i = v.size()-1;i >= 0 ; i--){
        cout<<v[i];
    }
}

void digitsRec(int n){ // through recursion // O(d) or O(log10 3) , O(d)
     if(n == 0) return ;
     digitsRec( n / 10 );
     cout<< n % 10 ;
}

void sum(int n){ // // O(d) or O(log10 3) , O(1) d is no of digits
    int sum = 0;
    while(n > 0){
        int num = 0;
        num = n % 10;
        sum += num;
        n /= 10 ;
    }
    cout<<"Sum of digits is : "<<sum;
}

void count(int n){ // // O(d) or O(log10 3) , O(1) d is no of digits
    int count =0;
    while(n > 0){
        int num = 0;
        num = n % 10;
        count++;
        n /= 10 ;
    }
    cout<<"Digits are : "<<count;
}
int main(){
    int n;
    cout<<"Enter a Number : ";
    cin>>n;

    digits(n);
    cout<<endl;

    digitsRec(n);
    cout<<endl;

    sum(n);
    cout<<endl;

    count(n);
    cout<<endl;
}