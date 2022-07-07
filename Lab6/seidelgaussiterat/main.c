#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,itmax,it,n;
    FILE* file_r =fopen("data.in","r");
    FILE* file_w =fopen("data.out","w");
    float a[10][10],b[10],x[10],y[10],s,eps,max;
    fscanf(file_r,"%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(file_r,"%f",&a[i][j]);
    for(i=1;i<=n;i++)
        fscanf(file_r,"%f",&b[i]);
    fscanf(file_r,"%f%f",&eps,&itmax);
    for(i=1;i<=n;i++)
        fscanf(file_r,"%f",&x[i]);
    it=0;
    for(i=1;i<=n;i++)
    {
        s=0;
        for(j=1;j<=n;j++)
            s+=a[i][j];
        if(a[i][i]<fabs(s-a[i][i]))
        {
            fprintf(file_w,"Nu putem aplica metoda Jacobi");
            return 0;
        }
    }

    do
    {
        max=0;
        for(i=1;i<=n;i++)
        {
            s=0;
            for(j=1;j<i;j++)
                s+=a[i][j]*y[j];
            for(j=i+1;j<=n;j++)
                s+=a[i][j]*x[j];
            y[i]=(b[i]-s)/a[i][i];
                max=(max<fabs(y[i]-x[i]))? fabs(y[i]-x[i]): max;
        }
        for(i=1;i<=n;i++)
            x[i]=y[i];
        it++;
    }while((max>eps)||(it>itmax));
    if(it>itmax)
    {
        fprintf(file_w,"Nu se poatte obtine solutia in %d iteratii, cu precizia %f",itmax,eps);
        return 0;
    }
    fprintf(file_w,"Solutia obtinuta in %d iteratii cu precizia %f este:\n",it,eps);
    for(i=1;i<=n;i++)
        fprintf(file_w,"x[%d]=%f\n",i,x[i]);
    return 0;
}
