#include<iostream>
#include<vector>
using namespace std;
int main(){
    // pair<int,pair<char,int>> p ={1,{'a',5}};
    // cout<<p.first<<endl;
    // cout<<p.second.first<<endl;
    // cout<<p.second.second<<endl;
    
    vector<pair<int,int>> vec={{1,2},{2,3},{3,4}};
    vec.push_back({4,5}); // insert
    vec.emplace_back(5,6); // int place objects create
    for(auto p : vec){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
} 