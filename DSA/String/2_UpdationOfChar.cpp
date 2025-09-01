#include<iostream>
#include<string>
using namespace std;
int main(){
  // update a at even position means odd indexs
  string s="killer";
  cout<<"Original : "<<s<<endl;
  for(int i=1;i<s.size();i++){
      if(i%2!=0)  s[i]='a';
  }
  cout<<"Updated : "<<s<<endl;
}
