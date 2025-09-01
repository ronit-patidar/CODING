#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 4, 5, 9, 15, 18, 21, 24};
    int target = 24 ;
    int n = sizeof(arr) / sizeof(arr[0]);
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi)
    {
        // int mid=(hi+lo)/2;
        int mid = lo + (hi - lo) / 2;
        if (target == arr[mid])
        {
            cout << mid; // mid is index
            break;
        }
        else if (arr[mid] < target)
            lo = mid + 1;
        else if (arr[mid] > target)
            hi = mid - 1;
    }
}
