#include<iostream>
using namespace std;
void inputArray(int r,int c,int** Array){
    cout<<"Enter the elements of the Array: ";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>Array[i][j];

        }
    }
}
void displayArray(int r,int c,int** Array){
    cout<<endl<<"Elements are:";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<Array[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main(){
    int r1,r2,c1,c2;
    cout<<"Enter the number of rows and coloumns of the 1st array: ";
    cin>>r1>>c1;
    int Array1[r1][c1];
inputArray(r1,c1,Array1);
    cout<<"Enter the number of rows and coloumns of the 2nd array: ";   
    cin>>r2>>c2;
    int Array2[r2][c2];
inputArray(r2,c2,Array2);
    cout<<"The 1st Array";
displayArray(r1,c1,Array1);
    cout<<"The 2nd Array";
displayArray(r2,c2,Array2);    
}