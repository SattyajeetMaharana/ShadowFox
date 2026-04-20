#include<iostream>
#include<string>
using namespace std;
int main(){
    string str="sattya jeet";
    int v=0,c=0,s=0;
    for(int i=0; str[i]!=0; i++){
        if(str[i]=='a'||str[i]=='A'||str[i]=='e'||str[i]=='E'||str[i]=='i'||str[i]=='I'||str[i]=='o'||str[i]=='O'||str[i]=='u'||str[i]=='O'){
            v++;
        }
        else if(str[i]==' '){
            s++;
        }
        else{
            c++;
        }
    }
    cout<<"there are "<<s+1<<" words here"<<endl<<"vowels are "<<v<<endl<<"consonents are "<<c<<endl;
}