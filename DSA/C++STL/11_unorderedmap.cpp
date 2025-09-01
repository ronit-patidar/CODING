#include<iostream>
#include<map>
#include<unordered_map>
#include<map>
using namespace std;
int main(){ 
    unordered_map<string,int> m;
    m.emplace("tv", 100);
    m.emplace("lapi", 100);
    m.emplace("fridge", 100);
    m.emplace("air", 100);
 
     for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
     }

}  