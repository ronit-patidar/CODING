#include<iostream>
using namespace std;

int main() {
    int rows = 4;
    int cols = 4;
    int arr[rows][cols] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int minr = 0, maxr = rows - 1;
    int minc = 0, maxc = cols - 1;

    while (minc <= maxc && minr <= maxr) {

        for (int i = minc; i <= maxc; i++) {
            cout << arr[minr][i] << " ";
        }
        minr++;

        for (int j = minr; j <= maxr; j++) {
            cout << arr[j][maxc] << " ";
        }
        maxc--;

        if (minr <= maxr) {  // Check needed to avoid extra print
            for (int i = maxc; i >= minc; i--) {
                cout << arr[maxr][i] << " ";
            }
            maxr--;
        }

        if (minc <= maxc) {  // Check needed to avoid extra print
            for (int j = maxr; j >= minr; j--) {
                cout << arr[j][minc] << " ";
            }
            minc++;
        }
    }
}
