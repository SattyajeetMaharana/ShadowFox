interface Member{
void callback();}

class Customer implements Member{
String name;
public Customer(String name){
this.name=name;}
public void callback(){
System.out.println("i will visit from"+name);}}

class Store{
Member M[]=new Member[5];
int count=0;
void reg(Member m){
M[count++]=m;}
void inviteSale(){
for(Member x:M){
x.callback();}}}

class Demo{
public static void main(String args[]){
Customer c1=new Customer("John");
Customer c2=new Customer("Ram");
Store s=new Store();
s.reg(c1);
s.reg(c2);
s.inviteSale();
}}
