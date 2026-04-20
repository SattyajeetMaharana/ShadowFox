#include <iostream>
#include<cmath>
using namespace std;
int main(){
    int n=1987;
    int rev=0;
    while(n>0){
        int r=n%10;
        n/=10;
        rev=rev*10 +r;
        
    }
    cout<<rev;
    }
      