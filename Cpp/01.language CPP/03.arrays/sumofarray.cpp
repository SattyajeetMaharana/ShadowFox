#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    int A[n],sum=0;
    cout<<"Enter the elements of the Array"<<endl;
    for(int i=0; i<n; i++){
        int j=i+1;
        cout<<"element "<<j<<" is ";
        cin>>A[i];
    }
    cout<<"The elements of the arrya are"<<endl;
    for(int i=0; i<n; i++){
        cout<<A[i]<<"\t";
    }
    cout<<"\nThe sum of the elements of the array is ";
    for(int i=0; i<n; i++){
        sum+=A[i];
    }
    cout<<sum;
}