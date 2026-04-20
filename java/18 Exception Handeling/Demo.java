package exception;
class negativeDimException extends Exception{
public String toString(){
 return " Dimention cannot be negative !!";}}

class Demo{
public int area(int l,int b) throws negativeDimException{
if(l<0 || b<0)
throw new negativeDimException();
else 
return l*b;}
public static void main(String args[]){
Demo d=new Demo();
try{
System.out.println(d.area(5,-1));}
catch(negativeDimException e){
System.out.println(e);
}}}