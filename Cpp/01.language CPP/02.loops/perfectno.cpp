#include<iostream>
using namespace std;
int main(){
    int n,sum=0;
    cout<<"Enter a number to check:";
    cin>>n;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            sum+=i;
        }
    }
    if(sum==2*n){
    cout<<"its a perfect number.";
    }
    else{
        cout<<"its not a perfect number"<<sum;
    }
return 0;
}