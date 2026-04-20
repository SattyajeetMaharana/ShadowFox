#include<iostream>
using namespace std;
int max(int a,int b,int c){
    if(a>b && a>c)
    return a;

    else if(b>c)
    return b;

    else
    return c;
}
int main(){
    int x,y,z,m;
    cout<<"Enter any 3 numbers to check:";
    cin>>x>>y>>z;
    m= max(x,y,z);
    cout<<"Greatest number among them is:"<<m<<endl;
}
