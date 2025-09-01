#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isPalindrom(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
       if (s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int main(){
   string s;
   cout<<"Enter a string : ";
   getline(cin,s);
   if(isPalindrom(s)==true) 
   cout<<"String is palindrom ";
   else
   cout<<"Strin is not palindrome";
}
