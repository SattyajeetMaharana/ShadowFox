class GCD{
static int Common(int m,int n){
while(m!=n){
if(m>n)
m=m-n;
else
n=n-m;}
return m;
}
public static void main(String args[]){
int a=22,b=451;
System.out.println(Common(a,b));
}}