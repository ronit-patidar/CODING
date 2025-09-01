#include<iostream>
#include<stack>
using namespace std;
int prio(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2; 
}
string solve(string val1, string val2, char ch){
    // prefix op val 1 val2
    string s="";
    s.push_back(ch);
    s+=val1;
    s+=val2;
    return s;
}

int main(){
    string s = "(7+9)*4/8-3"; 
    stack<string> val; 
    stack<char> op; 

    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 48 && s[i] <= 57){
            val.push(to_string(s[i] - 48));
        }
        else { 
            if(op.size() == 0 ) op.push(s[i]); 
            else if(s[i]=='(') op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    char ch = op.top(); 
                    op.pop(); 
                    string val2 = val.top(); 
                    val.pop();
                    string val1 = val.top(); 
                    val.pop(); 
                    string ans = solve(val1,val2,ch); 
                    val.push(ans); 
                }
                op.pop(); // opening bracket pop
            }
             else if(prio(op.top()) < prio(s[i]))    op.push(s[i]);
            else {
                while(op.size() > 0 && prio(op.top()) >= prio(s[i])){
                    char ch = op.top(); 
                    op.pop(); 
                    string val2 = val.top(); 
                    val.pop(); 
                    string val1 = val.top(); 
                    val.pop(); 
                    string ans = solve(val1,val2,ch); 
                    val.push(ans); 
                }
                op.push(s[i]); 
            }
        }
    }

    while(op.size() > 0){
        char ch = op.top(); 
        op.pop();
        string val2 = val.top(); 
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1,val2,ch); 
        val.push(ans); 
    }

    cout << val.top()<<endl;; 
}
