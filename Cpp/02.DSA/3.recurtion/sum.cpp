#include<iostream>
using namespace std;
long factorial(long n){
    if(n==0)
    return 1;
    else 
    return n*factorial(n-1);
}
int main(){
    long n;
    cout<<"Enter a number :";
    cin>>n;
    long f=factorial(n);
    cout<<"factorial is :"<<f;
    return 0;
}
