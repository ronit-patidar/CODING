#include<iostream>
using namespace std;
// if constructor is private then we can't create object directly
// can access through other class
class Box{
    int width;
    //  private ctor
    Box(int _w):width(_w){};
    public:
    int getwidth()const {
        return width;
    }
    void setwidth(int _val){
        width=_val;
    }
    friend class Boxfactory;
};
class Boxfactory{
    int count;
    public:
    Box getABox(int _w){
        ++count;
        return Box(_w);
    }
};
int main(){
    Boxfactory bfact;
    Box b=bfact.getABox(5);
    cout<<b.getwidth()<<endl;
    return 0;
}
