#include<iostream>
#include<string>
using namespace std;
bool isconsonant(char ch) {
    // ch=int(ch) is commented out, so it's not being used.

    // If the ASCII value of 'ch' is less than 65 (less than 'A') return false (invalid character)
    if (int(ch) < 65) return false; 
    
    // If the ASCII value of 'ch' is greater than 122 (greater than 'z') return false (invalid character)
    else if (int(ch) > 122) return false; 
    
    // If the ASCII value of 'ch' is between 90 ('Z') and 97 ('a') (i.e., not an alphabetic character)
    else if (int(ch) > 90 && int(ch) < 97) return false;
    
    // If 'ch' is a vowel ('a', 'e', 'i', 'o', 'u' in both lowercase and uppercase), return false
    else if (ch == 'a' || ch == 'A') return false;
    else if (ch == 'e' || ch == 'E') return false;
    else if (ch == 'i' || ch == 'I') return false;
    else if (ch == 'o' || ch == 'O') return false;
    else if (ch == 'u' || ch == 'U') return false;
    
    // If none of the conditions matched (i.e., the character is an alphabetic consonant), return true
    else return true;
}
int main(){
    string s;
    cout<<"Enter the char in string : ";
    cout<<endl;
    getline(cin,s);
    int count = 0;
    for(int i=0;i<s.length();i++){
        if(isconsonant(s[i])) count++;
    }
    cout<<count<<endl;
    }

