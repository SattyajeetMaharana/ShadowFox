#include<iostream>
using namespace std;
int BS(int *Arr,int l,int h,int key){
    while(l<=h){
    int mid=(l+h)/2;
    if(Arr[mid]==key)
    return mid;
    else if(key<mid) 
    h=mid-1;
    else
    l=mid+1;}
    return -1;}

int main(){
    int Arr[100];
    for(int i=0; i<100; i++)
    Arr[i]=i+1000;
    int l=0;int h=sizeof(Arr)/sizeof(Arr[0])-1;int key;
    cout<<"Enter a nmber to search:";
    cin>>key;
    int An= BS(Arr,l,h,key);
    if(An<0)
    cout<<"not found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    else 
        cout<<"Found at "<<An;
}