#include<iostream>
using namespace std;
int main() {
    int n,count=0;
    cout<<"enter a number to check:";
    cin>>n;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            count++;
        }

    }
    if(count==2){
        cout<<"ITs a prime number";

    }
    else{
        cout<<"its not a prime number";
    }
    return 0;
}