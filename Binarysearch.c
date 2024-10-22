#include<stdio.h>
int main()
{
    int a[20],e,i,item,n,low=0,high=n-1,mid;
    printf("Enter Limit:");
    scanf("%d",&n);
    printf("Enter Array Elements:");
    scanf("%d",&e);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter Element to search:");
    scanf("%d",&item);
    {
        mid=low+(high-low)/2;
        if(a[mid]==item)
        	return mid;
        if(a[mid],item)
        {
        	low=mid+1;
        }
        else
        {
        	high=mid-1;
        }
     }
     for(i=0;i<n;i++)
    {
        printf("Found");
    }
}
