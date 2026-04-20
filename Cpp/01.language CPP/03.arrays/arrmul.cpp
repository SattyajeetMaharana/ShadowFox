#include<iostream>
using namespace std;
int main() {
   int c1,c2,r1,r2;
   cout<<"Enter the no. of rows and columns for matrix A: ";
   cin>>r1>>c1;
   cout<<"Enter the no. of rows and columns  for matrix B: ";
   cin>>r2>>c2;
   int A[r1][c1],B[r2][c2];
if(c1!=r2){
  cout<<"Multiplication can not be done \nBecause 2nd matrix's no. of row not eqaul to 1st matrix's no. of coulmns";
  return 0;
 }
//  input matrix
  cout<<"\nEnter elements of A matrix: "<<endl;
  for(int i=0; i<r1; i++){
    int i1=i+1;
    for(int j=0; j<c1;j++){
      int j1=j+1;
      cout<<"Enter the A"<<i1<<j1<<"Element:";
      cin>>A[i][j];  
    }
  }
  cout<<"\nEnter elements of B matrix: "<<endl;
  for(int i=0; i<r2; i++){
    int i1=i+1;
    for(int j=0; j<c2;j++){
      int j1=j+1;
      cout<<"Enter the B"<<i1<<j1<<"Element:";
      cin>>B[i][j];  
    }
  }
//   printing matrix
  cout<<"\nMatrix A is: "<<endl;
  for(int i=0; i<r1; i++){
    for(int j=0; j<c1;j++){
      cout<<A[i][j]<<"\t";
    }
    cout<<endl;
  }
  cout<<"\nMatrix B is: "<<endl;
  for(int i=0; i<r2; i++){
    for(int j=0; j<c2;j++){
      cout<<B[i][j]<<"\t";
    }
    cout<<endl;
  }
//   multiplication
  cout<<"The multiplication of A and B matrix is: "<<endl;
  int C[r1][c2];
  for(int i=0; i<r1;i++){
    for(int j=0; j<c2;j++){
        int sum=0;
        for(int k=0; k<r2; k++){
            sum+=A[i][k]*B[k][j];
           
        }
        C[i][j]=sum;
    }
  }
  cout<<"\nMatrix multiplication is: "<<endl;
  for(int i=0; i<r1; i++){
    for(int j=0; j<c2;j++){
      cout<<C[i][j]<<"\t";
    }
    cout<<endl;
  }


}
