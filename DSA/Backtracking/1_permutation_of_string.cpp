#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
// problem ?
// creating copies of original string and substr in every call
// tc=O(n!) sc=O(n)
void permutationsbrute(string ans,string original){
    if(original==""){
        cout<<ans<<endl;
        return ;
    }
    for(int i=0;i<original.size();i++){ 
        char ch=original[i];
        // substr(pos,len)
        string left=original.substr(0,i); // left substr
        string right=original.substr(i+1); // from index 2 to length (right substr)
        permutationsbrute(ans+ch,left+right); // call
    }
}
// tc=O(n!) sc=O(n)
void permutations(string &str,int idx){
   if(idx == str.size()-1){
        cout<<str<<endl;
        return ;
   }
   // set for every loop to avoid duplicates
   unordered_set<char> st;
   for(int i=idx;i<str.size();i++){
        if(st.count(str[i])) continue;
        st.insert(str[i]);    
        swap(str[i],str[idx]); // swap
        permutations(str,idx+1);
        swap(str[i],str[idx]); // backtracking
   }
}
int main(){
    string str="aba";
    permutations(str,0);
}