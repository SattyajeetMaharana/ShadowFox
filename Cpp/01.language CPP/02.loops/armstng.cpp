#include<iostream>
using namespace std;
int main(){
    int n,r,count=0;
    cout<<"Enter a number to check:";
    cin>>n;
    int orignalN=n;
    while(n>0){
        r=n%10;
        n/=10;
        int s=r*r*r;
        count+=s;
    }
    if(count==orignalN)
    cout<<"its an amstrong number.";

    else
    cout<<"its not an amstrong number";

    return 0;
    }