 // first negative numbers in every window of size k
 // brute force
 #include<iostream>
 #include<vector>
 using namespace std;
 int main(){
    int arr[]={2,-3,4,4,-7,-1,4,-2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    vector<int> ans;
    for(int i=0;i<=n-k;i++){
        int firstNegative=INT16_MAX;
        for(int j=i;j<=i+k;j++){
           if(arr[j]<0){
            firstNegative=arr[j];
            break;
           }
        }
        ans.push_back(firstNegative);
    }
    for(int i=0;i<ans.size();i++){
        std::cout<<ans[i]<<" ";
    }
 }