#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
// concatination -> adding two string
int main(){
    string s;
    cout<<"Enter a character : ";
    getline(cin,s);
    string temp =s;
    reverse(temp.begin(),temp.end());
    s=s+temp;
    cout<<s;
    
}