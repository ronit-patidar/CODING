#include<iostream>
using namespace std;
// 1 based indexing 
int fibo(int n){
    if(n==1 || n==2 ) return 1;
    return fibo(n-1)+fibo(n-2);
}
int main(){
      cout<<fibo(8);
}
/*
Euclid's Tree for fibo(8):

fibo(8)
|
|-- fibo(7)
|   |
|   |-- fibo(6)
|   |   |
|   |   |-- fibo(5)
|   |   |   |
|   |   |   |-- fibo(4)
|   |   |   |   |
|   |   |   |   |-- fibo(3)
|   |   |   |   |   |
|   |   |   |   |   |-- fibo(2) -> 1
|   |   |   |   |   |-- fibo(1) -> 1
|   |   |   |   |-- fibo(2) -> 1
|   |   |   |-- fibo(3)
|   |   |       |
|   |   |       |-- fibo(2) -> 1
|   |   |       |-- fibo(1) -> 1
|   |   |-- fibo(4)
|   |       |
|   |       |-- fibo(3)
|   |       |   |
|   |       |   |-- fibo(2) -> 1
|   |       |   |-- fibo(1) -> 1
|   |       |-- fibo(2) -> 1
|   |-- fibo(5)
|       |
|       |-- fibo(4)
|       |   |
|       |   |-- fibo(3)
|       |   |   |
|       |   |   |-- fibo(2) -> 1
|       |   |   |-- fibo(1) -> 1
|       |   |-- fibo(2) -> 1
|       |-- fibo(3)
|           |
|           |-- fibo(2) -> 1
|           |-- fibo(1) -> 1
|-- fibo(6)
    |
    |-- fibo(5)
    |   |
    |   |-- fibo(4)
    |   |   |
    |   |   |-- fibo(3)
    |   |   |   |
    |   |   |   |-- fibo(2) -> 1
    |   |   |   |-- fibo(1) -> 1
    |   |   |-- fibo(2) -> 1
    |   |-- fibo(3)
    |       |
    |       |-- fibo(2) -> 1
    |       |-- fibo(1) -> 1
    |-- fibo(4)
        |
        |-- fibo(3)
        |   |
        |   |-- fibo(2) -> 1
        |   |-- fibo(1) -> 1
        |-- fibo(2) -> 1
*/