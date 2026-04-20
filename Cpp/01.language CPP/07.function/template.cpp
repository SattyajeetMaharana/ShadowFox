#include<iostream>
using namespace std;
template<class T>

T maxim(T a,T b){
    return a>b?a:b;
}

int main(){
    int c=maxim<int>(22,4);
    cout<<c<<endl;
    return 0;
}