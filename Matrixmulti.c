#include<stdio.h>
void main()
{
    int a[10][10],b[10][10],res[10][10];
    int m,n,p,q,i,j,k;
    printf("Enter row and column of first matrix: ");
    scanf("%d%d",&m,&n);
    printf("Enter first matrix: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter row and column of second matrix: ");
    scanf("%d%d",&p,&q);
    printf("Enter second matrix: \n");
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
                res[i][j]=0;
                for(k=0;k<n;k++)
                {
                    res[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        printf("Result: \n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                
                printf("%d ",res[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Matrix multiplication not pssible");
    }
}
