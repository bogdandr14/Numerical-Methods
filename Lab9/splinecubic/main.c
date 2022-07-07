#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    float x[20], a[20], b[20], c[20], t[20], h[20], f[20], S, z[10];
    for(i = 0; i <= n; i++)
        scanf("%f", &x[i]);
    for(i = 0; i <= n; i++)
        scanf("%f", &f[i]);
    for(i = 1;i <= n; i++)
        h[i] = x[i] - x[i - 1];
    for(i = 1; i <= n - 1; i++)
        a[i] =2 * (h[i] + h[i + 1]);
    for(i = 1; i <= n - 2; i++)
    {
        b[i] = h[i + 1];
        c[i] = b[i];
    }
    for(i = 1; i <= n - 1; i++)
        t[i] = 6 * (f[i + 1] - f[i]) / h[i + 1] - 6 * (f[i] - f[i - 1]) / h[i];

    n--;
     for(i=1;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("Sistemul nu are solutie unica deoarece avem elementul diagonal nul in linia %d", i);
            return 0;
        }
        c[i]=c[i]/a[i];
        a[i+1]-=b[i]*c[i];
    }
    for(i=2;i<=n;i++)
        t[i]-=c[i-1]*t[i-1];
    if(a[n]==0)
    {
        printf("Sistemul nu are solutie unica deoarece avem elementul diagonal nul in linia %d",n);
        return 0;
    }
    t[n]/=a[n];
    for(i=n-1;i>=1;i--)
        t[i]=(t[i]-b[i]*t[i+1])/a[i];
    for(i=1;i<=n;i++)
        printf("u[%d]=%f\n",i,t[i]);

    n++;
    t[0]=t[n]=0;
    for(int q=1;q<=6;q++)
    {
    scanf("%f",&z[q]);
    for(i = 1; i <= n; i++)
        if(x[i - 1] < z[q] && z[q] <= x[i])
        {
            S = (t[i]*pow(z[q]-x[i-1],3)+t[i-1]*pow(x[i]-z[q],3))/(6*h[i])+(f[i]-t[i]*h[i]*h[i]/6)*(z[q]-x[i-1])/h[i]+(f[i-1]-t[i-1]*h[i]*h[i]/6)*(x[i]-z[q])/h[i];
            printf("%f\n",S);
            break;
        }
    }
    return 0;
}
