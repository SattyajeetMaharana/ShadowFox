#include<iostream>
using namespace std;
int main (){
 int a=10;
 int *ptr;
 ptr=&a;
 cout<<a<<"\n"<<ptr<<"\n"<<&a<<"\n"<<*ptr<<"\n"<<&ptr<<"\n"<<endl;
}