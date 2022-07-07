#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i,j,n,k;
    float a[11][11],b[11][12];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%f",&a[i][j]);
    for(i=1;i<=n;i++)
        scanf("%f",&b[i][n]);
    for(j=n-1;j>=1;j--)
        for(i=1;i<=n;i++)
    {
        b[i][j]=0;
        for(k=1;k<=n;k++)
            b[i][j]=b[i][j]+a[i][k]*b[k][j+1];
    }
    for(i=1;i<=n;i++)
    {
        b[i][n+1]=0;
        for(k=1;k<=n;k++)
            b[i][n+1]+=a[i][k]*b[k][1];
        b[i][n+1]*=-1;
    }
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=n;j++)
            printf("%f ",b[i][j]);
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n+1;j++)
            a[i][j]=b[i][j];
    int npc,lin,col,c[10][2];
    float piv,aux,eps,s;
    eps=0.00001;
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
        printf("\nx[%d]=%f",i,a[i][n+1]);
    return 0;
}
