#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
int main(){ 
    unordered_set<int> s;//random order , no lower and upper bound
    //set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    // cout<<"Lower Bound -> "<<*(s.lower_bound(4))<<endl;//4
    // cout<<"Upper Bound -> "<<*(s.upper_bound(4))<<endl;//5
     for(auto ele:s){
        cout<<ele<<" ";
     }

}  