#include<iostream>
#include<queue>
using namespace std;
// TC = O(n)
// TC = O(1)
void display(queue<int>& q){
   int n=q.size();
   for(int i=1;i<=n;i++){
         int x=q.front();
         cout<<x<<" ";
         q.pop();
         q.push(x);
   }
   cout<<endl;
}
// push , pop , size , front , back
int main(){
   queue<int> q;
   q.push(10);
   q.push(20);
   q.push(30);
   q.push(40);
   q.push(50);
   // push is done from back
   cout<<q.size()<<endl; //5
   cout<<q.back()<<endl; // 50
   q.pop(); // 20 30 40 50
    // pop is done from front
   cout<<q.size()<<endl;// 4
   cout<<q.front()<<endl;//20
   display(q);// 20 30 40 50
}