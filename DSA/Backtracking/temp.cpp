#include<iostream>
#include<vector>
using namespace std;
void permutation(string &str,int idx){
    if(idx == str.size()-1){
        cout<<str<<endl;
        return;
    }
    for(int i=idx;i<str.length();i++){
        swap(str[i],str[idx]);
        permutation(str,idx+1);
        swap(str[i],str[idx]); // backtrack
    }
}
int main(){
    string str="aba";
    permutation(str,0);
}