#include<iostream>
using namespace std;
int square (int s){
    int sq=s*s;
    return sq;
}
int main(){
    int s;
    cout<<"Enter a number : ";
    cin>>s;
    for(int i=1;i<=s;i++){
        cout<<square(i)<<endl;
    }

 
}