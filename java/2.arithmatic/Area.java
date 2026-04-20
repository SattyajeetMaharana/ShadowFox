import java.io.*;
import java.util.Scanner;
class Area{
public static void main(String args[]){
int a,b,c;
double s,area;
Scanner sc=new Scanner(System.in);
System.out.println("Enter the 3 sides of the Tringle: ");
a=sc.nextInt();
b=sc.nextInt();
c=sc.nextInt();
s=(a+b+c)/2d;
area=Math.sqrt(s*(s-a)*(s-b)*(s-c));
System.out.println("Area: "+area);
}}


