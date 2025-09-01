#include<iostream>
using namespace std;
int odd (int a,int b){
     for(int i=a+1;i<b;i++){
        if(i%2!=0) cout<<i<<endl;
     }  
}
int main(){
    odd(1,100);
    }

 
