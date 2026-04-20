#include<iostream>
using namespace std;
void makeArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<"\nEnter the value of "<<(i+1)<<"th element: ";
        cin>>arr[i];
    }
}
void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
}
int LSearch(int key,int arr[],int n){
    for(int i=0; i<n; i++){
        if(key==arr[i])
        return i;
    }
    return -1;
}
int BSearch(int key,int arr[],int n,int l,int h){
    int mid=(l+h)/2;
    if(arr[mid]==key)
    return mid;
    else if(arr[mid]<key)
    return BSearch(key,arr,n,mid+1,h);
    else if(arr[mid]>key)
    return BSearch(key,arr,n,l,mid-1);
    else
    return -1;

}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    makeArray(arr,n);
    printArray(arr,n);

    int key;
    cout<<"\nEnter a value to search:";
    cin>>key;

    int pos=LSearch(key,arr,n);
    cout<<"\nby Linear search!"<<endl;
    if(pos<0)
    cout<<"not found!!";
    else
    cout<<key<<" position of it is :"<<pos;

    pos=BSearch(key,arr,n,0,n-1);
    cout<<"\nby Binary search! "<<endl;
    if(pos<0)
    cout<<"not found!!";
    else
    cout<<key<<" position of it is :"<<pos;

}
