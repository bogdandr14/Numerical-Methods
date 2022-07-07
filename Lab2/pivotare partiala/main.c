#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main ()
{
    int i,j,k,n,lin;
    scanf("%d",&n);
    float a[10][11],s,piv,aux;
    for(i=1;i<=n;i++)
        for(j=1;j<=n+1;j++)
            scanf("%f", &a[i][j]);
    for(k=1;k<n;k++)
    {
        piv=fabs(a[k][k]);
        lin=k;
        for(i=k+1;i<=n;i++)
            if(piv<fabs(a[i][k]))
            {
                piv=fabs(a[i][k]);
                lin=i;
            }
        if(piv==0)
        {
            printf("Sistemul nu are solutie unica");
            return 0;
        }
        if(lin!=k)
            for(j=k;j<=n+1;j++)
            {
                aux=a[k][j];
                a[k][j]=a[lin][j];
                a[lin][j]=aux;
            }
        for(i=k+1;i<=n;i++)
        {
            a[i][k]/=a[k][k];
            for(j=k+1;j<=n+1;j++)
                a[i][j]=a[i][j]-a[i][k]*a[k][j];
        }
    }
    if(a[n][n]==0)
    {
        printf("Sistemul nu are solutie unica");
        return 0;
    }
    a[n][n+1]/=a[n][n];
    for(i=n-1;i>=1;i--)
    {
        s=0;
        for(j=i+1;j<=n;j++)
            s+=a[i][j]*a[j][n+1];
        a[i][n+1]=(a[i][n+1]-s)/a[i][i];
    }
    for(i=1;i<=n;i++)
        printf("x[%d]=%f\n",i,a[i][n+1]);
    return 0;
}
