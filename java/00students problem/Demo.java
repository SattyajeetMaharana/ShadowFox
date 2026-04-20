import java.util.Scanner;

public class Demo{
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
System.out.println("Enter your e-mail Address:");//john@gmail.com
String str=sc.nextLine();

if(str.matches("\\S[a-zA-Z].*@gmail.*")){
System.out.println("Its an Valid email address");
int index=str.indexOf('@');
int length=str.length();
String userName,domainName;
userName=str.substring(0,index);
domainName=str.substring(index+1,length);
System.out.println("User name is:"+userName+"\nDomain name is:"+domainName);
}
else
System.out.println("Its invalid");

}}