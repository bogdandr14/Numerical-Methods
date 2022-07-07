#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file=fopen("data.in","r");
    FILE* file_out=fopen("data.out","w");
    int n,i,j,h,k;
    float aux,a[10][11],piv,s;
    fscanf(file,"%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n+1;j++)
            fscanf(file,"%f",&a[i][j]);
    if(a[1][1]==0)
    {
        i=1;
        do
        {
            i++;
        }while(!(a[i][1]!=0 || i>n));
        if(i>n)
        {
            fprintf(file_out,"Sistemul nu are solutie unica");
            return 0;
        }
        for(i=1;i<=n;i++)
        {
            aux=a[i][1];
            a[i][1]=a[i][j];
            a[i][j]=aux;
        }
    }
    for(j=2;j<=n;j++)
        a[1][j]/=a[1][1];
    for(k=2;k<=n;k++)
    {
        i=k;
        do{
            s=0;
            piv=0;
            for(h=1;h<k;h++)
                s+=a[i][h]*a[h][k];
            piv=a[i][k]-s;
            i++;
        }while(!(piv!=0 || i>n));
        if(piv==0)
        {
            fprintf(file_out,"Sistemul nu are solutie unica");
            return 0;
        }
        if(i!=k+1)
            for(j=1;j<=n+1;j++)
            {
                aux=a[k][j];
                a[k][j]=a[i-1][j];
                a[i-1][j]=aux;
            }
        for(i=k;i<=n;i++)
        {
            s=0;
            for(h=1;h<k;h++)
                s+=a[i][h]*a[h][k];
            a[i][k]-=s;
        }
        for(j=k+1;j<=n;j++)
        {
            s=0;
            for(h=1;h<k;h++)
                s+=a[k][h]*a[h][j];
            a[k][j]=(a[k][j]-s)/a[k][k];
        }
    }
    a[1][n+1]/=a[1][1];
    for(i=2;i<=n;i++)
    {
        s=0;
        for(k=1;k<i;k++)
            s+=a[i][k]*a[k][n+1];
        a[i][n+1]=(a[i][n+1]-s)/a[i][i];
    }
    for(i=n-1;i>=1;i--)
    {
        s=0;
        for(j=i+1;j<=n;j++)
            s+=a[i][j]*a[j][n+1];
        a[i][n+1]-=s;
    }
    for(i=1;i<=n;i++)
        fprintf(file_out,"x[%d]=%f\n",i,a[i][n+1]);
    return 0;
}
