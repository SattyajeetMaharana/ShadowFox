class A implements Runnable{
public void run(){
for(int i=0; i<50; i++){
System.out.println(i+"hi");}}}

class Demos{
public static void main(String args[]){
A a=new A();
Thread t=new Thread(a);
t.start();
int i=0;
while(i<50){
System.out.println(" World"+i);
i++;}}}


