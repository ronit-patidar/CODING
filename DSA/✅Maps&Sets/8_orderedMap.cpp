#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
   // insertion , delete , searching takes O(log n)
   set<int> s;
   s.insert(5);
   s.insert(3);
   s.insert(7);
   for(int ele : s){ // print/store in sorted order
      cout<<ele<<" ";
   }
   cout<<endl;

   map<int,int> m; // SORT SCCORDING TO KEY
   m[2]=30;
   m[3]=10;
   m[1]=20;
   for(auto x : m){ // print in sorted order
      cout<<x.second<<" ";
   }
   cout<<endl;

   map<string,int> m2; // LEXOGRAPHICALLY 
   m2["Raghav"]=76;
   m2["Harsh"]=10; 
   m2["Sanket"]=52;
   for(auto x : m2){ // print in lexographicaly order
      cout<<x.first<<" "<<x.second<<endl;
   }

}
