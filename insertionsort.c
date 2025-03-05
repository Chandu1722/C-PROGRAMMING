#include<stdio.h>
int main()
{
   int size,i,j,temp,list[100];
   printf("enter the size of array:");
   scanf("%d",&size);
   printf("enter the elements into list:");
   for(i=0;i<size;i++)
   {
       scanf("%d",&list[i]);
   }
   for(i=0;i<size;i++)
   {
       temp=list[i];
       j=i-1;
       while(temp<list[j]&&(j>=0))
       {
           list[j+1]=list[j];
           j=j-1;
       }
       list[j+1]=temp;
   }
   printf("list after sorting:");
   for(i=0;i<size;i++)
    printf("%d ",list[i]);
  return 0;
}
