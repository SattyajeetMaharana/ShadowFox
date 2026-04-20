import java.util.Scanner;
class Circle{
private double radius;
public Circle(double r){
radius=r;}
public double Area(){
return Math.PI*radius*radius;}
public double Perimeter(){
return 2*radius*(Math.PI);}}

class Cylinder extends Circle{
private double height;
public Cylinder(double h,double r){
super(r);
height=h;}
public double Volume(){
return Area()*height;}}

class Check{
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
System.out.println("Enter value of Radius and Height: ");
double R=sc.nextDouble();
double H=sc.nextDouble();
Circle cr=new Circle(R);
Cylinder cy=new Cylinder(R,H);
System.out.println(cr.Area()+" "+cy.Volume());
}}
