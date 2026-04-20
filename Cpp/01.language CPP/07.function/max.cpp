#include<iostream>
using namespace std;
template<class T>

T max(T a,T b,T c){
return a>b&&a>c?a:b>c?b:c;
}
int main(){
   float a=3.6,b=6.7,c=75.6;
   float m= max(a,b,c);
   cout<<m<<endl;
}