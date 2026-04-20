#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
int power(int x,int n){
    if(n==0)
    return 1;
    return x*power(x,n-1);
}
int factorial(int n){
    if(n==0)
    return 1;
    return n*factorial(n-1);
}
void expo(int x,int n){
    int p=power(x,n);
    int f=factorial(n);
    if(n==0)
    cout<<1;
    else{
    expo(x,n-1);
    cout<<"  "<<p<<"/"<<f<<"  "; 
}}
int expoi(int x,int n){
    int p=power(x,n);
    int f=factorial(n);
    if(n==0)
    return 1;
    return expoi(x,n-1);
}
int main(){
    int x=10;
    int n=8;
    expo(x,n);
    cout<<endl<<expoi(x,n);
}