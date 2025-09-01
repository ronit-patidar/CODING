#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        string pre;
        pre[0]=0;
        for(int i=1;i<n+1;i++){
            if(customers[i-1]=='N') customers[i]=1;
            else if (customers[i]=='N') customers[i]=i;
            else customers[i]=0;
        }
    }
};