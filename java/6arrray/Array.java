class Array{
public static void main(String args[]){
int Arr[]={1,2,4,5,7,8,10,44,6,77,86};
int max1,max2;
max1=max2=Arr[0];
for(int i=0;i<7;i++){
if(Arr[i]>max1){
max2=max1;
max1=Arr[i];
}
else if(Arr[i]<max1 && Arr[i]>max2){
max2=Arr[i];
}}
System.out.println("2nd largest element is:"+max2);
}}
