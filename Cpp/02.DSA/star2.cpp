#include<bits/stdc++.h>
using namespace std;
void print(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<j+1<<"  ";            
        }
        // for(int k=0; k<n; k++){
        //     cout<<" ";
        // }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"enter the number n:";
    cin>>n;
    print(n);
    return 0;
}