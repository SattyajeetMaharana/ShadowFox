#include<iostream>
using namespace std;
int main(){
    int A[]={1,5,6,88,90,788,900,5432,345678};
    int mid,l=0,h=8;
    int key;
    cout<<"ENter a key to search:";
    cin>>key;
  while(l<=h){
    mid=(l+h)/2;
if(A[mid]==key){
    cout<<"fount it at index(0-8) :"<<mid;
    return 0;
    }
 else if(A[mid]<key){
        l=mid+1;
    }
else{
        h=mid-1;
    }
  }
  cout<<"not found";
  return 0;
}