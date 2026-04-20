#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter a string:";
    getline(cin,str);
    
    string rev;
  int l=(int)str.length();
  rev.resize(l);
  for(int i=0; i<l; i++){
    if(str[i]>=65 && str[i]<=90){
        str[i]+=32;
    }
  }
   for(int i=0,j=l-1; i<l; i++,j--){
        rev[j]=str[i];
    }
    rev[l]='\0';
    if(rev.compare(str)==0)
    cout<<"Palindrome";
    else
    cout<<"Not a palindrome";

    return 0;
}