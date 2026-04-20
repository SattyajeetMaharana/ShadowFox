#include<bits/stdc++.h>
using namespace std;
    bool check(int i,string s){
        if(i<=s.size()/2){
            if(s[i]!=s[s.size()-i-1]) return false;
            else check(i+1,s);
        }
        return true;
    }
    bool isPalindrome(string s) {
        int i=0;
        return check(i,s);
    }
    int main(){
        string str;
        cout<<"write here"<<endl;
        cin>>str;
        if(isPalindrome(str)) cout<<"it is palindrome";
        else cout<<"its not a palindrome.";
    }