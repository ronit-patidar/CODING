#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
       string s ="geeksforgeeks";
       vector<int> arr(26,0);
       for(int i=0;i<s.size();i++){
               char ch =s[i];
               int ascii = (int)ch;
               arr[ascii-97]++; // convert as alphabet counting
       }
       int mx=0;
       for(int i=0;i<26;i++){
          if(arr[i]>mx) mx =arr[i];
       }
        for(int i=0;i<26;i++){
          if(arr[i]==mx) {
            int ascii=i+97;
            char ch =(char)ascii;
            cout<<"Charactor -> "<<ch<<endl<<"Freq -> "<<mx<<endl;
          }
       }
    }
 