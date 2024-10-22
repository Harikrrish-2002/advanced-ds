#include<stdio.h>
int main()
{
    int a[20],e,i,item,n;
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
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
             printf("%d present at %d",item,i++);
        }
    }
}
