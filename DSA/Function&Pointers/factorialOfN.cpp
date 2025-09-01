#include<iostream>
using namespace std;
    // int fact =1;
    // for(int i=1;i<=n;i++){
    //     fact*=i;
    //     cout<<fact<<endl;
    // }
 int fact(int n){
    int fact =1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
 }   
int main(){
    int n;
    cout<<"Enter the value ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<fact(i)<<endl;
    }
}