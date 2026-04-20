import java.io.*;
class Swapping{
public static void main(String args[]){
int a=12,b=15;
System.out.println("Before swapping numbers are:"+a+"and"+b);
a=a^b;
b=a^b;
a=a^b;
System.out.println("AFter swapping numbers are:"+a+"and"+b);
}}