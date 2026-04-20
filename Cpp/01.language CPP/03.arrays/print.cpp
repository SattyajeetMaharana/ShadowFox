#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter the number of elements in the array: ";
    cin>>n;
    int A[n];
    cout<<"Enter the elements of the array:"<<endl;
for(int i=0; i<n; i++) {
    cout<<i+1<<"Element is:";
    cin>>A[i];
 }
for(auto x:A){
    cout<<x<<endl;
 }
    return 0;
}