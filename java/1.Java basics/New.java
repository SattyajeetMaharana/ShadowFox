import java.util.Scanner;
class New
{
public static void main(String[] args)
{
Scanner sc= new Scanner(System.in);
System.out.println("Enter a Number: ");
int n= sc.nextInt();
for(int i=0; i<10; i++){
System.out.println(i+1+" X "+n+" = "+n*(i+1));
}
}
}