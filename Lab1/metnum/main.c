#include<stdlib.h>
#include<stdio.h>

int main ()
{
    int i,j,k,n;
    scanf("%d",&n);
    float a[10][11],s;
    for(i=1;i<=n;i++)
        for(j=1;j<=n+1;j++)
            scanf("%f", &a[i][j]);
    for(k=1;k<n;k++){
        if(a[k][k]!=0)
            for(i=k+1;i<=n;i++)
            {
                a[i][k]/=a[k][k];
                for(j=k+1;j<=n+1;j++)
                    a[i][j]=a[i][j]-a[i][k]*a[k][j];
            }
        else
            return 0;}
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
