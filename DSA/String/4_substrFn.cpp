#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    // return the second half of even length string
    string s="abcdef";
    cout<<s.substr(3,s.size()); //(start,end+1)
}