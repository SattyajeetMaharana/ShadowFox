#include<iostream>
using namespace std;
int main(){
    int *ptr= new int[10];
    ptr[0]=12;
    ptr[1]=11;
    cout<<ptr[1]<<endl;

    delete []ptr;
    
    ptr=new int [20];
    ptr[11]=112;
    ptr[19]=90;
    cout<<ptr[19]<<endl;
}