#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    // int realNum=num;
    int rev;
    while(num>0){
        int rem =num %10;
        num /=10;
        rev =10 *rev +rem;
    }
    cout<<rev;

}