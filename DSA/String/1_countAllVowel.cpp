#include <iostream>
#include <string>
using namespace std;
int countVowel(string &str){
  int countV=0;
  for(int i=0;i<str.size();i++){
    if( str[i]=='a'  ||
        str[i]=='e'  ||
        str[i]=='i'  ||
        str[i]=='o'  ||
        str[i]=='u'  
    ){
      cout<<str[i]<<" ";
      countV++;
    }
  }
  return countV;
}
int countConsonent(string &str){
  int countC=0;
  for(int i=0;i<str.size();i++){
    if( str[i]=='a'  ||
        str[i]=='e'  ||
        str[i]=='i'  ||
        str[i]=='o'  ||
        str[i]=='u'  
    ) 
    continue;
    cout<<str[i]<<" ";
    countC++;
  }
  return countC;
}
// int countConsonent(string &str){
//   return str.size()-countVowel(str);
// }
int main(){
  string s="palindrome";
  int countV = countVowel(s);
  cout<<endl;
  int countC = countConsonent(s);
  cout<<endl;
  cout<<"Count Vowel : "<<countV<<endl;
  cout<<"Count Consonet : "<<countC<<endl;
  return 0;
}