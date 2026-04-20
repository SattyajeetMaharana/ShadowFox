#include<iostream>
#include<string>
using namespace std;
int main(){
    string str="sattyajeet";
    string::iterator it;
    int count=0;
    for(it=str.begin(); it!=str.end(); it++){
        count++;
    }
    cout<<"length of the string is "<<count<<endl;
}