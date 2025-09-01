#include<iostream>
#include<map>
using namespace std;
int main(){ 
    multimap<string,int> m;
    // can store multiple key and duplicate key
    // no square bracat notatation is used []
    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("tv", 100);

    //m.erase("tv"); // erase all
    m.erase(m.find("tv")); 
     for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
     }

} 