 // first negative numbers in every window of size k
 // if negative doesnt exist push back 1
 #include<iostream>
 using namespace std;
 int main(){
    int arr[]={2,-3,4,4,-7,-1,4,-2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int ans[n-k+1];
    int p=-1;
    for(int i=0;i<k;i++){
        if(arr[i]<0) {
            p=i; 
            break;
        }
    }
    if(p==-1) ans[0]=1;
    else ans[0]=arr[p];
    // sliding window
    int i=1;
    int j=k;
    while(j<n){
        if(p>=i) ans[i]=arr[p];
        else{ 
            p=-1;
              for(int x=i;x<=j;x++){
                 if(arr[x]<0) {
                    p=x;
                    break;
                 }
              }
            if(p!=-1)  ans[i]=arr[p];
            else ans[i]=1;   
        }
        i++;
        j++;
    }
    // TC = O(n)
    for(int i=0;i<n-k+1;i++){
        std::cout<<ans[i]<<" ";
    }
 }




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
