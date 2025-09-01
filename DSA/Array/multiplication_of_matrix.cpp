#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter 1st matrix row no : ";
    cin>>m;

    int n;
    cout<<"Enter 1st matrix col no : ";
    cin>>n;

    int p;
    cout<<"Enter 2nd matrix row no : ";
    cin>>p;

    int q;
    cout<<"Enter 2nd matrix col no : ";
    cin>>q;
 
    if(n!=p) cout<<"Matrix Multiplication not possible. ";
    else{
        // first matrix
        int a[m][n];
        cout<<"Enter elements of 1st matrix : ";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        // second matrix
        int b[p][q];
        cout<<"Enter elements of 2nd matrix : ";
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                cin>>b[i][j];
            }
        }
        // resultant
        int res[m][q];
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                res[i][j]=0;
                // multiplication 
                for(int k=0;k<n;k++){  // k < n or p both are equal
                   res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        cout<<"Matrix Multipliaction : "<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}