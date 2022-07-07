#include <stdio.h>
#include <stdlib.h>
float f1(float x)
{
    return x*x-2;
}
float f1d(float x)
{
    return 2*x;
}
float f2(float x)
{
    return 2*x-log(x)-4;
}
float f2d(float x)
{
    return 2-1.0/x;
}
int main()
{
    int it, itmax;
    float eps, x0, x1, dif;
    scanf("%f%f%d",&x0, &eps, &itmax);
    it=0;
    do
    {
        x1=x0- f2(x0)/f2d(x0);
        dif=fabs(x1-x0);
        x0=x1;
        it++;
    }while(dif>eps && it<=itmax);
    if(it>itmax)
    {
        printf("Nu se poate obtine solutia in %d iteratii, cu precizia %f", itmax, eps);
        return 0;
    }
    printf("Solutia obtinuta in %d iteratii cu precizia %f este %f", it, eps, x1);
    return 0;
}
