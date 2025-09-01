#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 1, 6, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // cyclic sort
    int i = 0;
    while (i < n)
    {
        int CorrectIdx = arr[i] - 1;
        if (i == CorrectIdx)
            i++;
        else
            swap(arr[i], arr[CorrectIdx]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}