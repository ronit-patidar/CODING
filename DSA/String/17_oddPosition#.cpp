#include<iostream>
using namespace std;
// at odd position not index
int main(){
    string s="";
    cout<<"Enter char in string : ";
    getline(cin,s);
    for( int i=0;i<s.size();i++){
        if(i%2==0) s[i]='#';
    }
    cout<<s<<endl;
}
