class Rotating{
public static void main(String args[]){
int Arr[]={1,2,3,4,5,6,7,8,9};
System.out.println("Array is:");
for(int x:Arr)
System.out.print(x+"  ");
System.out.println("\nAfter Left Shifting Array is:");
int temp=Arr[0];
for(int i=0;i<Arr.length-1;i++){
Arr[i]=Arr[i+1];
}
Arr[Arr.length-1]=temp;
for(int x:Arr)
System.out.print(x+"  ");
 Arr=new int[]{1,2,3,4,5,6,7,8,9};
System.out.println("\nAfter Right Shifting Array is:");
temp=Arr[Arr.length-1];
for(int i=Arr.length-1; i>0;i--){
Arr[i]=Arr[i-1];}
Arr[0]=temp;
for(int x:Arr)
System.out.print(x+"  ");
}}

