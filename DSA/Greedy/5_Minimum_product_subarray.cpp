#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minimumProduct(vector<int> &arr){
    int cnp=0,cnn=0,cnz=0;
    int prod_neg=1;
    int prod_pos=1;
    int largest_negative=INT16_MIN;
    for(int i=0;i<arr.size();i++){
       if(arr[i]>0) {
            cnp++;
            prod_pos *= arr[i];
       }
       if(arr[i]==0) cnz++;
       if(arr[i]<0){ 
            cnn++;
            prod_neg*=arr[i];
            largest_negative=max(largest_negative,arr[i]);
       }
    }
    if(cnn==0){
        if(cnz>0) return 0;
        else {
            auto it=min_element(arr.begin(),arr.end());
            return *it;
        }
    }
    else{
        if(cnn%2!=0){  // odd no of negative
          return prod_pos * prod_neg;
        }
        else{   // even no of negative  
          return (prod_neg/largest_negative)*prod_pos;
        }
    }
}
int main(){
    // vector<int> arr={-2,-3,1,4,-2};
    // vector<int> arr={-2,-3,1,4,-2,-5};
    // vector<int> arr={2,3,1,4,2};
    vector<int> arr={2,3,1,4,2,0};
    cout<<minimumProduct(arr)<<endl;
    return 0;
}