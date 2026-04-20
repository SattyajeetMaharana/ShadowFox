#include<iostream>
#include<cmath>
using namespace std;
int main() {
float a,b,c,d,r1,r2;
cout<<"Enter the value of a,b,c of the quadratic equation:";
cin>>a>>b>>c;
d=b*b-4*a*c;
r1=(-b+sqrt(d))/(2*a);
r2=(-b-sqrt(d))/(2*a);
if(d>=0)
cout<<"the roots of the equation are "<<r1<<" & "<<r2;
else
cout<<"imaginary roots.";
return 0;
}