#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cout<<"Enter the char in string of even length : ";
    cout<<endl;
    getline(cin,s);
    int n=s.size();
     int i=n/2;
     int j=s.size()-1;
     while(i<=j){
        swap(s[i],s[j]);
        i++;
        j--;
     }
     cout<<s;
    }

