#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file=fopen("data.in","r");
    FILE* file_out=fopen("data.out","w");
    int n;
    fscanf(file,"%d",&n);
    int i,j;
    float a[n+1],b[n],c[n],t[n+1];
    for(i=1;i<=n;i++)
        fscanf(file,"%f",&a[i]);
    for(i=1;i<n;i++)
        fscanf(file,"%f",&b[i]);
    for(i=1;i<n;i++)
        fscanf(file,"%f",&c[i]);
    for(i=1;i<=n;i++)
        fscanf(file,"%f",&t[i]);
    for(i=1;i<n;i++)
    {
        if(a[i]==0)
        {
            fprintf(file_out,"Sistemul nu are solutie unica deoarece avem elementul diagonal nul in linia %d", i);
            return 0;
        }
        c[i]=c[i]/a[i];
        a[i+1]-=b[i]*c[i];
    }
    for(i=2;i<=n;i++)
        t[i]-=c[i-1]*t[i-1];
    if(a[n]==0)
    {
        fprintf(file_out,"Sistemul nu are solutie unica deoarece avem elementul diagonal nul in linia %d",n);
        return 0;
    }
    t[n]/=a[n];
    for(i=n-1;i>=1;i--)
        t[i]=(t[i]-b[i]*t[i+1])/a[i];
    for(i=1;i<=n;i++)
        fprintf(file_out,"x[%d]=%f\n",i,t[i]);
    return 0;
}
