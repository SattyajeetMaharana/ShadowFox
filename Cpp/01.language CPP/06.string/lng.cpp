#include<iostream>
#include<cstring>
using namespace std;
int main() {
    char s1[100]="sattyajeet ";
    char s2[50]="mr maharana";
    cout<<strlen(s1)<<" length of s1 and "<<strlen(s2)<<" length of s2"<<endl;
    cout<<strcat(s1,s2)<<endl;
cout<<strcpy(s1,s2);
cout<<s1<<s2;
return 0;
}
