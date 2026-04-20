#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Array{
    int *p;
    int size;
 
};
int main(){
struct Array Ar;
cout<<"Enter the size of array: ";
cin>>Ar.size;
Ar.p=(int *)malloc(Ar.size*sizeof(int));
cout<<"Enter the elements of the array: ";
for(int i=0;i<Ar.size;i++){
    cin>>Ar.p[i];
}
for(int i=0; i<Ar.size; i++){
    cout<<Ar.p[i]<<"\t";
}
free(Ar.p);
}