#include<iostream>
#include<queue>
using namespace std;
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
// TC = O(n)
// SC = O(1)
int removeEvenPosi(queue<int>& q){
    int n=q.size();
    for(int i=0;i<n;i++){
       if(i%2==0) q.pop();
       else {
        int x=q.front();
        q.pop();
        q.push(x);
       }
    }
    // for(int i=0;i<n;i++){
    //     if(i%2!=0){
    //         int x=q.front();
    //         q.push(x);
    //     }
    //     q.pop();
    // }
}
int main(){
    queue<int> q;
    q.push(1); // even
    q.push(2);
    q.push(3); // even
    q.push(4);
    q.push(5); //even
    q.push(6);
    removeEvenPosi(q);
    display(q);
}