package Exceptions;
import java.util.Scanner;
static class E{
public float divide(float a, float b){
return a/b;}
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
System.out.println("Enter value of a and b:");
float a=sc.nextFloat();
float b=sc.nextFloat();
try{
float c=divide(a,b);
System.out.println(c);}
catch(ArithmaticException e){
System.out.println("Divisble by 0 is not allowed!!\n"+e);}
}}