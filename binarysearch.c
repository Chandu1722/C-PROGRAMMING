#include<stdio.h>
int main()
{
    int a[30];
    int i,n,key,loc=-1,low,high,mid;
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the elements into array");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter the key element");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<high)
    { 
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            loc=mid;
            break;
        }
        else if(key<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    if(loc==-1)
        printf("key not found");
    else
        printf("key found at %d",loc);
    return 0;
}
