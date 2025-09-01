#include<iostream>
using namespace std;
class abc{
    mutable int x;
    int *y;
    //const int z;
    public:
    //  // constructor : old style
    // abc(int _x,int _y,int _z=0){
    //     x=_x;
    //     y=new int (_y);
    //     z=_z; // gives error
    // }
     //initializer_list
     // const variable can be initialize
    //  abc(int _x,int _y,int _z=0) : x(_x),y(new int (_y)),z(_z){
    //     cout<<"Initiallisation list";
    //  }



    int getX() const{// no change forever
         x=50; 
        return x;
    }  
    void setX(int val){
        x=val;
    }  
    int getY() const {
        return *y;
    }  
    void setY(int val){
        *y=val;
    }  
    void printABC(const abc &a){
        cout<<a.getX()<<" "<<a.getY()<<endl;
        // only calls const function otherwise gives error
    }
};
int main(){
    abc a;
    cout<<a.getX()<<endl;
    cout<<a.getY()<<endl;
    return 0;
}

int main2(){
    // //1)
    // const int x=10;
    //  // x=11;
    // cout<<x<<endl;


    // //2)
    // const int *a=new int (2);// CONST data , NON-CONST pointer
    //  //int const *a=new int (2); same as upper line
    // //*a=20;
    // cout<<*a<<endl;
    // int b=20;
    // a=&b;
    // cout<<*a<<endl;


    // CONST pointr ,but NON CONST data.
    //3) 
    // int *const a=new int (3);
    // cout<<*a<<endl;
    // *a=20; // chal jayega
    // cout<<*a<<endl;
    // // a=&b // nahi chalega


    //4)
    const int *const a= new int(10);
    cout<<*a<<endl;
    //*a=50;
     //a=100;
    return 0;
 

}