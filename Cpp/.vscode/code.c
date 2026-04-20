#include<stdio.h>
 main(){
  int a=5;
  int *ptr=&a;
  int **pptr=&ptr;
  printf("%u",ptr);
}