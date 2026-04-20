import java.util.Scanner;
public class Q3{
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
System.out.println("Enter date in DD/MM/YYYY format:");
String Date=sc.nextLine();
if(Date.matches("[0-3][0-9]/[01][0-9]/[0-9]{4}"))
System.out.println("Its an Valid date.");
else
System.out.println("Invalid date");
}}
