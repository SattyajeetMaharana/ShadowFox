import java.util.Scanner;
class RevInt{
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
System.out.println("Enter A number :");
int A=sc.nextInt();
int Rev=0;
while(A>0){
int r=A%10;
Rev=Rev*10+r;
A=A/10;
}
System.out.println("After reverse number is:"+Rev);
}}
