#include<iostream>
using namespace std;
void insert(int *A,int index,int value,int &n ){
    for(int i=n; i>index; i--){
        A[i]=A[i-1];}
    A[index]=value;
    n++;}

void display(int *A,int n){
for(int i=0; i<n; i++)
cout<<A[i]<<endl;}

int main(){
    int A[100];
    int n;
cout<<"Enter the no. of values you want to insert: "<<endl;
cin>>n;
cout<<"Enter the values: ";
for(int i=0; i<n; i++){
    cin>>A[i];}
int index,value;
    cout<<endl<<"Enter the index and value:";
    cin>>index>>value;
insert(A,index,value,n);
display(A,n);
// cout<<n;
}