#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    // string to long long
    string str="1234567891234";
    long long x=stoll((str));
    cout<<x;

    cout<<endl;
    cout<<endl;


    // string to int
    string s="1234";
    int y=stoi((s));
    cout<<y;

    cout<<endl;
    cout<<endl;

    
    string st="000012345";
    long long z=stoll((st));
    cout<<z;
}