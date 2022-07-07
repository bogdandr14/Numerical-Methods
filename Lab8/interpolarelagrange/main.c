#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file_in = fopen("data.in","r");
    FILE* file_out = fopen("data.out","w");
    int n,i,j,k;
    float L,P,z,x[10],f[10];
    fscanf(file_in,"%d",&n);
    for(i=0;i<=n;i++)
        fscanf(file_in,"%f",&x[i]);
    for(i=0;i<=n;i++)
        fscanf(file_in,"%f",&f[i]);
    fscanf(file_in,"%f",&z);
    if(z<x[0]||z>x[n])
    {
        fprintf(file_out,"Nu putem optimiza in f");
        fclose(file_in);
        fclose(file_out);
        return 0;
    }
    for(i=0;i<=n;i++)
        if(z==x[i])
        {
            fprintf(file_out,"Valoarea aproximativa a functiei f in %f este %f",z,f[i]);
            fclose(file_in);
            fclose(file_out);
            return 0;
        }
    L=0;
    for(k=0;k<=n;k++)
    {
        P=1;
        if(f[k]!=0)
        {
            for(i=0;i<=n;i++)
                if(i!=k)
                    P=P*(z-x[i])/(x[k]-x[i]);
            L=L+f[k]*P;
        }
    }
    fprintf(file_out,"Valoarea aproximativa a functiei f in %f este %f",z,L);
    fclose(file_in);
    fclose(file_out);
    return 0;
}
