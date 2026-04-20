#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char s1[20]="sattyajeet";
    char s2[20]="t";
    char s3[20]="satyajeet";

    cout<<strstr(s1,s2)<<endl;
    cout<<strchr(s1,'a')<<endl;
    cout<<strcmp(s1,s3)<<endl;

    return 0;
}