#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> &vec){ // printing through itrator
    cout<<"Vector elements are : ";
    for(auto it = vec.begin() ; it < vec.end() ; it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
}

void revprint(vector<int> &vec){ // printing through itrator
    cout<<"Vector elements are in reverse : ";
    for(auto it = vec.rbegin() ; it < vec.rend() ; it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> vec;
    // size and capacity
    vec.emplace_back(1); // 1 1
    vec.emplace_back(2); // 2 2
    vec.push_back(3); // 3 4
    vec.push_back(4); // 4 4
    vec.push_back(5); // 5 8
    print(vec);
    revprint(vec);
    cout<<"Size : "<<vec.size()<<endl;
    cout<<"capacity : "<<vec.capacity()<<endl;
    cout<<"Element at idx 2 is : "<<vec.at(4)<<endl;
    cout<<"Element at idx 2 is : "<<vec[4]<<endl;;
    cout<<"Front ele : "<<vec.front()<<endl;
    cout<<"Back ele : "<<vec.back()<<endl;
    // vec.erase(vec.begin()+3);
    vec.erase(vec.begin()+1,vec.begin()+3);
    // vec.erase(vec.begin(),vec.end());
    vec.insert(vec.begin()+1,2);// pos(itrator),val
    vec.insert(vec.begin()+2,3);
    vec.clear();
    cout<<"Size : "<<vec.size()<<endl;
    cout<<"capacity : "<<vec.capacity()<<endl;
    cout<<"isEmpty : "<<vec.empty(); // check to either vec is empty or not
    //print(vec);
    return 0;
}