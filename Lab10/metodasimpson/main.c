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
    float a,b,eps,h,s1,s2,I0,I1,mid;
    int n,i;
    scanf("%f %f %f %f", &a, &b, &eps, &mid);
    n=1;
    I1=(f(a,mid)+4*f((a+b)/2,mid)+f(b,mid))*(b-a)/6;
    do{
        n*=2;
        h=(b-a)/n;
        I0=I1;
        s1=0;
        for(i=1;i<=n-1;i++)
            s1+=f(a+i*h,mid);
        s2=0;
        for(i=0;i<=n-1;i++)
            s2+=f(a+i*h+h/2,mid);
        I1=(f(a,mid)+2*s1+4*s2+f(b,mid))*h/6;
    }while(fabs(I1-I0)>eps);
    printf("Valoare integralei, obtinuta cu precizia %f, este %f",eps,I1);
    return 0;
}
