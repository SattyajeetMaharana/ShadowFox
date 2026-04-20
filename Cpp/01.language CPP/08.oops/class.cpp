#include<iostream>
#include<cmath>
using namespace std;

class rectangle {
    private:
    float length;
    float breadth;

    public:
    float setLength(int l){
        length=l;
    }
    float setBreadth(int b){
        breadth=b;
    }
    float readLength(){
        return length;
    }
    float readBreadth(){
        return breadth;
    }
    float area(){
        return length*breadth;
    }
    float perimeter(){
        return 2*(length + breadth);
    }
    float diagonal(){
        return sqrt((length*length)+(breadth*breadth));
    }
};
int main(){
    rectangle r;
    rectangle *p;
    p= &r;
    float l,b;
    cout<<"Enter the length: ";
    cin>>l;
    cout<<"& breadth:";
    cin>>b;
    p->setBreadth(b);
    p->setLength(l);

    cout<<"Length is "<<p->readLength()<<endl;
    cout<<"Breadth is "<<p->readBreadth()<<endl;
    
    
}