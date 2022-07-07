#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file_in = fopen("data.in","r");
    FILE* file_out = fopen("data.out","w");
    int n,i,j,k,q,ok;
    float N,P,s,z[10],x[10],f[10];
    fscanf(file_in,"%d",&n);
    for(i=0;i<=n;i++)
        fscanf(file_in,"%f",&x[i]);
    for(i=0;i<=n;i++)
        fscanf(file_in,"%f",&f[i]);
    for(i=0;i<n;i++)
        fscanf(file_in,"%f",&z[i]);
    for(q=0;q<n;q++)
    {
        ok=1;
        if(z[q]<x[0]||z[q]>x[n])
        {
            fprintf(file_out,"Nu putem optimiza in f\n");
            ok=0;
        }
        for(i=0;i<=n;i++)
            if(z[q]==x[i])
            {
                fprintf(file_out,"Valoarea aproximativa a functiei f in %f este %f",z[q],f[i]);
                ok=0;
            }
        if(ok)
        {
            N=f[0];
            for(k=1;k<=n;k++)
            {
                s=0;
                for(j=0;j<=k;j++)
                {
                    P=1;
                    if(f[j]!=0)
                    {
                        for(i=0;i<=k;i++)
                            if(i!=j)
                                P=P*(x[j]-x[i]);
                        s=s+f[j]/P;
                    }
                }
                P=1;
                for(i=0;i<k;i++)
                    P=P*(z[q]-x[i]);
                N=N+s*P;
        }
        fprintf(file_out,"Valoarea aproximativa a functiei f in %f este %f\n",z[q],N);
        }

    }

    fclose(file_in);
    fclose(file_out);
    return 0;
}
