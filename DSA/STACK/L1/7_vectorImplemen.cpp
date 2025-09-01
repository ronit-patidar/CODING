#include<iostream> 
#include<vector>    
using namespace std; 
class stack {
public:
    vector<int> v;
    stack() { 
    }
    void push(int val) { 
        return v.push_back(val); 
    }

    void pop() {
        if (v.size() == 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        v.pop_back();
    }

    int top() {
        if (v.size() == 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return v[v.size() - 1];
    }

    int size() {
        return v.size();
    }

    void display(stack& st) {
        for (int i = 0; i < st.size(); i++) {
            cout << st.v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    stack st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    cout << st.size() << endl;
    cout << st.top() << endl;
    st.display(st);
}
