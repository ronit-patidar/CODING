#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq={1,2,3,4,5};
    for(auto ele:dq){
        cout<<ele<<" ";
    }
    cout<<endl;
    cout<<dq[2]<<endl;
    // random access in deque is possible 
    return 0;
}