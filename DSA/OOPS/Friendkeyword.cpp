#include<iostream>
using namespace std;
class A{
    private:
    int x;
    public:
    A(int _val):x(_val){}
    int getx() const {  return x;}
    void setx(int _val){x=_val;}
    friend class B;    // b ko mera private member ka access de do
    friend void print(const A &);    // print ko mera private member ka access de do
};
// class B{
//     public:
//     void print(const A &a){
//         cout<<a.getx()<<endl; // through getter and setters
//     }
// };
class B{
    public:
    void print(const A &a){
        cout<<a.x<<endl;
    }
};
void print(const A &a){
    cout<<a.x<<endl;
}
int main (){
   A a(5);
   B b;
   b.print(a);
   print(a);
}