import java.io.*;
import java.util.Scanner;
class Roots{
public static void main(String args[]){

int a,b,c;
double D,x1,x2,i1,i2;
Scanner sc=new Scanner(System.in);
System.out.println("Enter the values od a,b,c for the Quadratic equation ax2 + bx +c=0 :");
a=sc.nextInt();
b=sc.nextInt();
c=sc.nextInt();
D=(double)b*b-4*a*c;
if(D>0){
x1=(-b+Math.sqrt(D))/(2*a);
x2=(-b-Math.sqrt(D))/(2*a);
System.out.println("The roots are: "+x1+" and "+x2);
}
else if(D==0){
x1=x2=-b/(2*a);
System.out.println("The roots are: "+x1+" and "+x2);
}
else{
x1=-(double)b/(2*a);
i1=Math.sqrt(-D)/(2*a);
x2=-(double)b/(2*a);
i2=Math.sqrt(-D)/(2*a);
System.out.println("The roots are: "+x1+"+"+i1+"i and "+x2+"-"+i2+"i");
}}}