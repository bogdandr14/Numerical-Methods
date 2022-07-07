#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main ()
{
    int i,j,k,n,lin,col,c[10][2],npc;
    float a[10][11],s,eps,piv,aux;
    scanf("%f%d",&eps,&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n+1;j++)
            scanf("%f", &a[i][j]);
    npc=0;
    for(k=1;k<n;k++)
    {
        piv=fabs(a[k][k]);
        lin=k;
        col=k;
        for(j=k;j<=n;j++)
            for(i=k;i<=n;i++)
                if(piv<fabs(a[i][j]))
                {
                    piv=fabs(a[i][j]);
                    lin=i;
                    col=j;
                }
        if(fabs(piv)<=eps)
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
        if(col!=k)
        {
            npc++;
            c[npc][0]=k;
            c[npc][1]=col;
            for(i=1;i<=n;i++)
            {
                aux=a[i][k];
                a[i][k]=a[i][col];
                a[i][col]=aux;
            }
        }
        for(i=k+1;i<=n;i++)
        {
            a[i][k]/=a[k][k];
            for(j=k+1;j<=n+1;j++)
                a[i][j]=a[i][j]-a[i][k]*a[k][j];
        }
    }
    if(fabs(a[n][n])<=eps)
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
    for(i=npc;i>=1;i--)
    {
        aux=a[c[i][0]][n+1];
        a[c[i][0]][n+1]=a[c[i][1]][n+1];
        a[c[i][1]][n+1]=aux;
    }
    for(i=1;i<=n;i++)
        printf("x[%d]=%f\n",i,a[i][n+1]);
    return 0;
}
