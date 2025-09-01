#include<iostream>
#include<stack>
using namespace std;

void pushatbottom(stack<int> &s, int val) {
    stack<int> s2;
    while(s.size() != 0) {
        s2.push(s.top());
        s.pop();
    }
    s.push(val);
    while(s2.size() != 0) {
        s.push(s2.top());
        s2.pop();
    }
}

void pushatanyidx(stack<int> &s, int idx, int val) { // 0 based idx
    if(idx == 0) {
        pushatbottom(s, val);
        return;
    }
    stack<int> s2;
    while(s.size() > idx) {
        s2.push(s.top());
        s.pop();
    }
    s.push(val);
    while(s2.size() > 0) {
        s.push(s2.top());
        s2.pop();
    }
}

void print(stack<int> &s) {
    stack<int> s2;
    while(s.size() > 0) {
       s2.push(s.top());
       s.pop();
    }
    while(s2.size() > 0) {
       cout << s2.top() << " ";
       s.push(s2.top());
       s2.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);
    cout << s.size() << endl;
    print(s);

    pushatbottom(s, 50);
    cout << s.size() << endl;
    print(s);
    
    pushatanyidx(s, 2, 45);
    cout << s.size() << endl;
    print(s);

    return 0;
}
