#include<iostream>
using namespace std;
int main(){
    int n,r;
    cout<<"Enter a number to display its digits:";
    cin>>n;
    cout<<"The digits are:"<<endl;
    while(n>0){
       r=n%10;
       n/=10;
       cout<<r<<endl;
    }
    return 0;
}