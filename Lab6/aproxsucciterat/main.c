#include <stdio.h>
#include <stdlib.h>
float g1(float x)
{
    return sqrt(10)/sqrt(x+4);
}
float g2(float x)
{
    return sqrt(sqrt(x))+2;
}
float g3(float x)
{
    return cbrt(x)-1;
}
int main()
{
    int it,itmax;
    float x0,x1,eps,dif;
    scanf("%f%f%d",&x0,&eps,&itmax);
    it=0;
    do
    {
        x1=g3(x0);
        dif=fabs(x1-x0);
        x0=x1;
        it++;
    }while(dif>eps && it<=itmax);
    if(it>itmax)
    {
        printf("Nu se poate obtine solutia in %d iteratii cu precizia %f",itmax,eps);
        return 0;
    }
    printf("Solutia obtinuta in %d iteratii cu precizia %f este %f",it,eps,x1);
    return 0;
}
