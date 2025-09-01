#include<iostream>
#include<climits>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    string arr[]={"0123","0023","456"
    ,"00182","940","002901"};
  
    int maxi=stoi(arr[0]); // max integer
    string maxS = arr[0]; // max String
    for(int i=0;i<6 ;i++){
        int x=stoi(arr[i]);
        if(x>maxi) {
            maxi=x;
            maxS=arr[i];
        }
    }
    cout<<maxi<<endl<<maxS;
}