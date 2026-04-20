#include<iostream>
#include<string>
using namespace std;
int main(){
    string email;
    cout<<"Enter the gmail:";
    getline(cin,email);
int i=(int)email.find("@gmail.com");
    string userName=email.substr(0,i);
    cout<<"The user name is :"<<userName<<endl;
}
