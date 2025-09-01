#include<iostream>
#include<string>
using namespace std;
long long binary_to_decimal(string &binary){
    long long n=binary.size();
    long long result=0;
    for(int i=n-1;i>=0;i--){
        char ch = binary[i];
        long long num=ch-'0';
        result+=num*(1<<(n-i-1)); // num * 2^(n-i-1)
    }
    return result;
}

string decimal_to_binary(int num){
    string result="";
    while(num>0){
        if(num%2==0) {// even
            result='0'+result;// prepend
        }
        else {// odd
            result='1'+result;// prepend
        }
        //num = num / 2;
        num=num>>1;// divide by 2
    }
    return result;
}
int main(){
    //string str="001101";
    string str="110010110";
    cout<<binary_to_decimal(str)<<endl;
    cout<<decimal_to_binary(24)<<endl;
    return 0;
}