#include<iostream>
#include<string>
using namespace std;
int main(){
    string str="sattyajeet   maharna";
    for(int i=0; str[i]!=0; i++){
        str[i]-=32;
    }
    cout<<str<<endl;
    return 0;
}