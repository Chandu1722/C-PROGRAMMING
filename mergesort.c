#include<stdio.h>

void merge(int arr[],int l,int  m,int h)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=h-m;
    int L[n1];
    int R[n2];
    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j]){
            arr[k]=L[i];
        i++;
        }
        else{
            arr[k]=R[j];
        j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
    i++;
    k++;
    }
    while(j<n2){
        arr[k]=R[j];
    j++;
    k++;
    }
}
void mergesort(int arr[],int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}
void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    int arr[]={38,5,36,87,22,17};
    int n=6;
    printf("array before sorting");
    printarray(arr,n);
    mergesort(arr,0,n-1);
    printf("after sorting:");
    printarray(arr,n);
  return 0;
}
