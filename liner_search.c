#include<stdio.h>
int linearsearch(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}
int main()
{
    int arr[]={5,43,34,5,17,22}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=43;
    int index=linearsearch(arr,n,key);
    if(index!=-1)
        printf("key found at index  %d",index);
    else 
        printf("key not found");
  return 0;
}
 
