#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    char arr[100][100];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(i>=j)
            cout<<"* ";
        }
        cout<<endl;
    }
}





