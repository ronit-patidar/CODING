#include <iostream>
using namespace std;
int main()
{
    int arr[5][6] = {{0, 0, 0, 0, 1, 1}, {0, 0, 1, 1, 1, 1}, {0, 0, 0, 1, 1, 1}, 
    {0, 1, 1, 1, 1, 1}, {0, 0, 0, 1, 1, 1}}; // binary matrix
    int m = 5;
    int n = 6;
    int row = 0;
    int x=1;
    int maxOnes=0;
    for (int i = 0; i < m; i++)
    { // bs on every row
    int count=0;// no of 1 in ith rows
        int lo = 0;
        int hi = n - 1;
        int firstidx = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[i][mid] == x)
            {
                if (arr[i][mid] == x)
                    if (mid == 0)
                    {
                        firstidx = mid;
                        break;
                    }
                    else if (arr[i][mid - 1] != x)
                    {
                        firstidx = mid;
                        break;
                    }
                    else
                    { // arr[mid-1]=x
                        hi = mid - 1;
                    }
            }
            else if (arr[i][mid] < x)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        if (firstidx != -1)
           count=n-firstidx;
        if(maxOnes<=count){
            maxOnes=count;
            row=i;
        }
    }
    cout<<row<<" "<<maxOnes;
}