#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
best deal = value/weight 
high value and less weight
ratio of value/weight should be high
*/
// custom comparator

bool cmp(pair<int,int> &p1,pair<int,int> &p2){
        // pair<int,int> first-> value , second -> weight
    double r1=(p1.first*1.0)/(p1.second*1.0);
    double r2=(p2.first*1.0)/(p2.second*1.0);
        // Multiplying by 1.0 ensures floating-point division instead of integer division,
        //  preserving decimal values during the division of integers.
    return r1 > r2;
        // if true return r1
        // if false return r2
}
double fractionalKnapsack(vector<int> &profit,vector<int> &weights,int n,int W){ // TC = O(n*logn) // SC = (sorting algo)
    vector<pair<int,int> > arr;
    for(int i=0;i<n;i++){
            arr.push_back({profit[i],weights[i]});
    }
    sort(arr.begin(),arr.end(),cmp); // sort in acc to value by weight ratio
    double result=0; // to store profit
    for(int i=0;i<n;i++){
        if(arr[i].second < W){
            result += arr[i].first;
            W -= arr[i].second;
        }
        else{
            result += (arr[i].first*1.0)/(arr[i].second*1.0)*W; // IMP
            W=0;
            break;
        }
    }
    return result;
}
int main(){
    vector<int> profit={60,100,120};
    vector<int> weights={10,20,30};
    int W=50;
    int n=3;
    cout<<fractionalKnapsack(profit,weights,n,W);
    return 0;
}
