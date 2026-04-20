class Outer {
void show(){
class Inner{
void Ishow(){System.out.println("Inner class");}}
Inner i=new Inner();
i.Ishow();}
    
}
class Test1{
    public static void main(String[] args){
        Outer o=new Outer();
        o.show();
    }
}
