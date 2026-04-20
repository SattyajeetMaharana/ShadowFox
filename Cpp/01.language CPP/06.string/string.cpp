#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="sattya     jeet7 maha79    rana";
    int length=0;
    int c=0,sp=0,v=0;
    for(int i=0; s[i]!=0; i++){
        length++;
        if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122){
            if(s[i]=='a'|| s[i]=='A'|| s[i]=='e'|| s[i]=='E'|| s[i]=='i'|| s[i]=='I'|| s[i]=='o'|| s[i]=='O'|| s[i]=='u'|| s[i]=='U'){
            v++;
        }
            else{
                c++;
            }
        }
        if(s[i]==' '){
            sp++;
        }
    }
    int count=0;
    for(int i=0; i<length; i++){
      if(s[i]==' ' && s[i+1]!=' '){
        count++;
      }
    }
    cout<<"words in the string "<<count+1<<endl;
    cout<<"length of the string is "<<length<<endl;
    cout<<"no of voules "<<v<<endl;
    cout<<"no of consonents "<<c<<endl;
    cout<<"special charecter are "<<length-c-v-sp<<endl;
 return 0;
}