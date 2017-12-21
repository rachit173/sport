#include<stdio.h>
int main(){
  int i,num,j;
  printf("Enter the number for finding factorial: ");
  scanf("%d",&num);
  for(int i=1;i<num;i++)
    j=j*i;
  printf("Factorial of %d : %d\n",num,j);

}
