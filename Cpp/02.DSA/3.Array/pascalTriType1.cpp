#include<iostream>
using namespace std;

int pascalTriangle(int r, int c, int ans){
    c-=1,r-=1;
    if(c==0)  return ans;
    ans*=((r-c+1)/(c));
    pascalTriangle(r,c,ans);
    return ans;
}

int main(){
    int row,clm;
    int ans=1;
    cout<<"Enter the row no and Column no:";
    cin>>row>>clm;
    ans=pascalTriangle(row,clm,ans);
    cout<<ans;
    return 0;

}