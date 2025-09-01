#include <iostream>
using namespace std;
// tc = O(n)
// sc = O(1)
int fact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
// tc = O(n)
// sc = O(1)
void permutation(int n,int r){
    if (r > n) {
        cout << "Invalid input! r should be ≤ n.\n";
        return;
    }
    int nfact=fact(n);
    int nrfact=fact(n-r);
    int npr=nfact/nrfact;
    cout<<"permutation : "<<npr<<endl;
}
// tc = O(n)
// sc = O(1)
void combination(int n,int r){
    if (r > n) {
        cout << "Invalid input! r should be ≤ n.\n";
        return;
    }
    int nfact=fact(n);
    int rfact=fact(r);
    int nrfact=fact(n-r);
    int ncr=nfact/(nrfact*rfact);
    cout<<"combination : "<<ncr<<endl;
}
int main() {
    int n, r;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter r: ";
    cin >> r;
    permutation(n,r);
    combination(n,r);
    return 0;
}
