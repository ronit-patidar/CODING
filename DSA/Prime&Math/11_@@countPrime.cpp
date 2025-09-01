// leetcode :  204
// link  :  https://leetcode.com/problems/count-primes


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    void fillseive(vector<bool> &seive){
        int n=seive.size();
        for(int i=2;i<=sqrt(n);i++){
            if(seive[i]){
                    for(int j=i*i;j<n;j+=i){
                    seive[j]=0;
                }
            }
        }
    }
    int countPrimes(int n) {
        if(n<=2) return 0;
        //n=n-1; // strictly less than n
        vector<bool> seive(n,1); // 1 for prime , 0 for composite
        fillseive(seive);
        if(n>0) seive[0]=0;
        if(n>1) seive[1]=0;
        int count=0;
        for(int i=2;i<n;i++){
            if(seive[i]==1) count++;
        }
        return count;
    }
};
int main() {
    Solution sol;
    cout << sol.countPrimes(0) << " (Expected: 0)" << endl;       // No primes less than 0
    cout << sol.countPrimes(1) << " (Expected: 0)" << endl;       // No primes less than 1
    cout << sol.countPrimes(2) << " (Expected: 0)" << endl;       // No primes less than 2
    cout << sol.countPrimes(10) << " (Expected: 4)" << endl;      // Primes: 2, 3, 5, 7
    cout << sol.countPrimes(20) << " (Expected: 8)" << endl;      // Primes: 2, 3, 5, 7, 11, 13, 17, 19
    cout << sol.countPrimes(36) << " (Expected: 11)" << endl;     // Primes: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31
    cout << sol.countPrimes(100) << " (Expected: 25)" << endl;    // 25 primes less than 100
    cout << sol.countPrimes(1000000) << " (Expected: 78498)" << endl; // Primes less than 1,000,000    return 0;
}
