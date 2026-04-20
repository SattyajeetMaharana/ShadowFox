import java.util.Scanner;
class Rectangle{
public double l;
public double b;
public double area(){
return l*b;}
public double perimeter(){
return 2*(l+b);}
public boolean isSquare(){
if(l==b)
return true;
else 
return false;}}

class Demo{
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
Rectangle R=new Rectangle();
System.out.println("Enter length and bredth: ");
R.l=sc.nextDouble();
R.b=sc.nextDouble();
System.out.println("Area is: "+R.area());
System.out.println("Perimeter is: "+R.perimeter());
if(R.isSquare())
System.out.println("Its a square!!");
}}


