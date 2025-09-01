#include<iostream>
using namespace std;
// vvv imp
// pre in post  order
void pip(int n){
    if(n==0) return;
    cout<<"Pre  : "<<n<<endl;
    pip(n-1);
    cout<<"In   : "<<n<<endl;
    pip(n-1);
    cout<<"Post : "<<n<<endl;
}
int main(){
    pip(1); cout<<endl;
    //  pip(2); cout<<endl;
    // pip(3);cout<<endl;
    // pip(4);cout<<endl;
}