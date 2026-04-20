import java.util.Scanner;
import java.io.*;
class Parent{
public int ip=10;
public void sum(){
System.out.println("Sum method called from Parent");}}
class Child extends Parent{
public int ic=20;
public void sum(){
System.out.println("Sum method called from child");}}
class Demo{
public static void main(String args[]){
Parent p=new Child();
p.sum();
System.out.println(p.ip);
//System.out.println(p.ic);
Child c=new Child();
c.sum();}}