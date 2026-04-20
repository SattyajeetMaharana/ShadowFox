import java.util.Scanner;
class Product{
private String itemNo;
private String name;
private double price;
private int quantity;
//                               Get methods
public String getItemNo(){
return itemNo;}
public String getName(){
return name;}
public double getPrice(){
return price;}
public int getQuantity(){
return quantity;}
//                               Set methods
public double setPrice(double p){
if(p>0)
price=p;
else
price=0;}
public int setQuantity(int q){
if(q>0)
quantity=q;
else
quantity=0;}
//                               Constructors
Product(String itemNo,String name){
this.itemNo=itemNo;
this.name=name;
}