import java.util.Scanner;
class OddEven{
public static void main(String args[]){
int a;
Scanner sc=new Scanner(System.in);
System.out.println("Enter a number to check if its even or odd:");
a=sc.nextInt();
if(a%2==0)
System.out.println(a+" is an Even number.");
else
System.out.println(a+" is an odd number.");
}}