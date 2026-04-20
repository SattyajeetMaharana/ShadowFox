#include<iostream>
using namespace std;


// class declaration
class rectangle{
   int length;
   int breadth;

 public:
    rectangle(){
         setLength(1);
         setBreadth(1);
    }
    rectangle(int l=1,int b=1){
         setLength(l);
         setBreadth(b);
    }
   void setLength(int l);
   void setBreadth(int b);
   int readLength();
   int readBreadth();
   int area();
   int perimeter();
   friend ostream &operator<<(ostream &out,rectangle &r);
};


// main function
int main(){
 rectangle r(7);
    cout<<r;
}


// other functions of class rectangle
   void rectangle::setLength(int l){
       if(l>0)
       length=l;
       else
         length=1;
   }
   void rectangle::setBreadth(int b){
       if(b>0)
       breadth=b;
       else
         breadth=1;
   }
    int rectangle::readLength(){
         return length;
    }
    int rectangle::readBreadth(){
        return breadth;
    }
    int rectangle::area(){
        return length*breadth;
    }
    int rectangle::perimeter(){
        return 2*(length+breadth);
    }
    ostream &operator<<(ostream &out,rectangle &r){
        out<<"Its length is "<<r.readLength()<<" and breadth is "<<r.readBreadth()<<endl;
        return out;
        
       }

