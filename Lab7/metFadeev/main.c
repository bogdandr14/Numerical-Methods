#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,k,h;
    float b[10][10],d[10][10],a[10][10],c[10];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%f",&a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j)
                b[i][j]=1;
            else
                b[i][j]=0;
    for(k=1;k<=n-1;k++)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                d[i][j]=0;
                for(h=1;h<=n;h++)
                    d[i][j]+=a[i][h]*b[h][j];
            }
        c[k]=0;
        for(i=1;i<=n;i++)
            c[k]+=d[i][i];
        c[k]=c[k]/k*(-1);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)
                    b[i][j]=d[i][j]+c[k];
                else
                    b[i][j]=d[i][j];
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            d[i][j]=0;
            for(h=1;h<=n;h++)
                d[i][j]+=a[i][h]*b[h][j];
        }
    c[n]=0;
    for(i=1;i<=n;i++)
        c[n]+=d[i][i];
    c[n]=c[n]/n*(-1);
    if(c[n]==0)
        printf("Matricea nu este inversabila");
    else
        printf("Matricea inversabila este ");
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=n;j++)
            printf("%f ",-b[i][j]/c[n]);
    }
    printf("\nCoeficientii polinomului caracteristic sunt:\n");
    for(i=1;i<=n;i++)
        printf("%f ",c[i]);
    return 0;
}
