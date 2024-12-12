#include<stdio.h>
void main()
{
    int a[10][10],b[10][10],c[10][10];
    int m,n,p,q,i,j,k;
    printf("Enter the Row and Column of matrix 1:");
    scanf("%d%d",&m,&n);
    printf("Enter First matrix:");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the Row and Column of matrix 2:");
    scanf("%d%d",&p,&q);
    printf("Enter Second matrix:");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    if(n==p)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                c[i][j]=0;
                for(k=0;k<n;k++)
                {
                    c[i][j]=a[i][j]+b[i][j];
                }
            }
        }
        printf("Result Matrix:\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                printf("%d",c[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Impossible...");
}