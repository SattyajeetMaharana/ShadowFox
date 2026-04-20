abstract class A{
abstract public void show(); }
class B extends A{
public void show(){
System.out.println("Over Ridden successfully!!");}}

class Demo{
public static void main(String args[]){
B obj=new B();
obj.show();
}}