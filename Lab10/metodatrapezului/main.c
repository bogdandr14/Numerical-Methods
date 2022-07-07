#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x, float mid)
{
    if(x<mid)
        return 0.4*pow(x+1,3)+0.6*(x+1)-5*x;
    else
        return 1./(x+1);
}
int main()
{
    float a,b,eps,h,s,I0,I1,mid;
    int n,i;
    scanf("%f %f %f %f", &a, &b, &eps, &mid);
    n=1;
    I1=(f(a,mid)+f(b,mid))*(b-a)/2;
    do{
        n*=2;
        h=(b-a)/n;
        I0=I1;
        s=0;
        for(i=1;i<=n-1;i++)
            s+=f(a+i*h,mid);
        I1=(f(a,mid)+2*s+f(b,mid))*h/2;
    }while(fabs(I1-I0)>eps);
    printf("Valoare integralei, obtinuta cu precizia %f, este %f",eps,I1);
    return 0;
}
