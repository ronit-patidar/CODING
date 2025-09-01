#include<iostream>
#include<map>
using namespace std;
int main(){ 
     map<string,int> m;

     m["tv"]=100;
     m["laptop"]=100;
     m["headphone"]=50;
     m["tablet"]=120;
     m["watch"]=50;
     
     m.insert({"buds",25});
     m.emplace("camera",25);
    // m.erase("tv");
     for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
     }
     cout<<endl;
     cout<<"count -> "<<m.count("laptop")<<endl; // first 
     cout<<"count -> "<<m["laptop"]<<endl; // second
     
     if(m.find("camera")!=m.end()){
        cout<<"Found"<<endl;
     }
     else {
        cout<<"Not found"<<endl;
     }
} 