#include<iostream>
using namespace std;
class abc{
    public:
    int x,y;
    void print() const {
        //this parameter belong to objet
        // cout<<x<<" "<<y<<endl;
        cout<<this->x<<" "<<this->y<<endl;
    }
};
int main(){
   abc obj1={1,2};
   abc obj2={3,4};
   obj1.print();// hidden pointer this pointer releted obj 1
   obj2.print();// hidden pointer this pointer releted obj 2
}