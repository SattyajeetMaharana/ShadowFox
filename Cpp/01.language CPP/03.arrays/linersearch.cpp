#include<iostream>
using namespace std;
int main() {
  int A[]={22,44,11,33,55,66,77,88,99,00};
  int key;
    cout<<"Enter a key to search here:";
    cin>>key;
  for(int i=0; i<10; i++) {
    int j=i+1;
    if(A[i]==key){
    cout<<"found it at "<<j<<" place of the array"<<endl;
    return 0;
    } 
}
    cout<<"not found"<<endl;
    return 0;
}