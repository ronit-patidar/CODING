#include<iostream>
#include<queue>
#include<iostream>
using namespace std;
int main(){ 
    // priority_queue<int> q;// max heap sort in desending
    //  q.push(5);
    //  q.push(3);
    //  q.push(10);
    //  q.push(4);
    //  while(!q.empty()){
    //     cout<<q.top()<<" ";
    //     q.pop();
    //  }
    //  cout<<endl;

    priority_queue< int, vector<int>,greater<int> > q;// min heap sort in aesending
     q.push(5);
     q.push(3);
     q.push(10);
     q.push(4);
     while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
     }
     cout<<endl;

} 