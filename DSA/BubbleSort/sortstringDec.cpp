#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string s="AZYZXBYDXJK";
    string str;
    for(int i=0;i<s.size();i++){
        if(s[i]>='X'){
            str.push_back(s[i]);
        }
    }
    //sort(str.begin(),str.end());
    for(int i=0;i<str.size()-1;i++){
        bool flag=true;
        for(int j=0;j<str.size()-1-i;j++){
            if(str[j]>str[j+1]){
                swap(str[j],str[j+1]);
                flag=false;
            }
        }
        if(flag==true){//swap didnot happen
          break;
        }
    }
    cout<<str;
    }