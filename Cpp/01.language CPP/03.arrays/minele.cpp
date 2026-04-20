#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the no. elements in the array";
    cin>>n;
    int A[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        int j=i+1;
        cout<<"element "<<j<<" is: ";
        cin>>A[i];
    }
    int min=A[0];
    for(int i=1; i<n; i++){
      if(min>A[i]){
        min=A[i];
      }
    }
    cout<<"the minimum no. of the array is "<<min;
}