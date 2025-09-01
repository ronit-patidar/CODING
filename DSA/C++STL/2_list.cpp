#include<iostream>
#include<list>
using namespace std;
int main(){
  list <int> l={5,3,1,2};
//   l.push_back(1);
//   l.push_back(2);
//   l.push_front(3);
//   l.push_front(5);
  for(auto ele : l){
    cout<<ele<<" ";
  }
  cout<<endl;
  //cout<<l[2]<<endl;
  // random access in list is not possible 
  cout<<endl;
}