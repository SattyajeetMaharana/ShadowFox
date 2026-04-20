class Outer{
int a=10;
class Inner{
int b=20;
void display(){
System.out.println(a+"From Inner class"+b);
}}
void show(){
Inner i=new Inner();
System.out.println(i.b+"From Outer class");
}}
class Test{
public static void main(String args[]){
Outer o=new Outer();
Outer.Inner i=new Outer().new Inner();
System.out.println(i.b);
i.display();
o.show();
}}
