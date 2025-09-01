#include<iostream>
#include<unordered_map>
using namespace std; 
int main(){
     // map<key,value> pair
    unordered_map<string,int> m;

    m["Ronit"]=69; // O(1) insert
    m["Rosh"]=70;
    m["Sahil"]=72;

    m.erase("Rosh");
    // random order print
    for( auto p: m ){ // O(1)
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;
    cout<<"Size : "<<m.size()<<endl;
    cout<<m["Ronit"]<<endl;
}
