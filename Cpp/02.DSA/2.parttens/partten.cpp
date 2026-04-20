#include<iostream>
using namespace std;
void pattern1(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern2(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<"*  ";
        }
        cout<<endl;
    }
}
void pattern4(int n){
for(int i=1; i<=n; i++){
    for(int j=1; j<=n-i; j++){
        cout<<"  ";
    }
    for(int k=1; k<2*i; k++){
        cout<<"* ";
    }
    cout<<endl;
}
}
void pattern5(int n){
    for(int i=1;i<=n;i++){
        for(int j=1; j<=i-1;j++){
            cout<<"  ";
        }
        for(int k=1; k<2*(n-i+1);k++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern6(int n){
    for(int i=1; i<n; i++){
        int i2=i-(n+1)/2;
        if(i<=(n+1)/2){
            for(int j=1; j<=n-i; j++){
                cout<<"  ";
            }
            for(int k=1; k<2*i; k++ ){
                cout<<"* ";
            }
            cout<<endl;
        }
        else{
            for(int j=1; j<=i2; j++){
                cout<<"  ";
            }
            for(int k=1; k<2*(n-i2+1); k++){
                cout<<"* ";
            }
            cout<<endl;
        }
    }
}
void pattern7(int n){
    for(int i=1; i<=n;i++){
        if(i<=(n+1)/2){
            for(int j=1; j<=i; j++){
                cout<<"* ";
            }
            cout<<endl;
        }
        else{
            for(int j=1; j<=n+1-i; j++){
                cout<<"* ";
            }
            cout<<endl;
        }
    }
}
void pattern8(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if((i+j)%2==0){
                cout<<"0 ";
            }
            else{
                cout<<"1 ";
            }
        }
        cout<<endl;
    }
}
void pattern9(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        for(int k=1; k<=2*(n-i); k++){
            cout<<"  ";
        }
        for(int l=i; l>=1; l--){
            cout<<l<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cout<<endl<<"Enter: ";
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        // pattern1(n);
        // pattern2(n);
        // pattern4(n);
        // pattern5(n);
        // pattern6(n);
        // pattern7(n);
        // pattern8(n);
        pattern9(n);

    }
}