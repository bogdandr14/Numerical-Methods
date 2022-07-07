#include <stdio.h>
#include <stdlib.h>
#include<math.h>
float f(float x, float y)
{
    return 2*y/x;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    float X,XX,x[n],Y,YY,y[n],eps,k1,k2,h,aux;
    for(i=0;i<=n;i++)
        scanf("%f",&x[i]);
    scanf("%f%f",&y[0],&eps);
    i=0;
    do
    {
        X=x[i];XX=x[i+1];Y=y[i];
        h=XX-X;
        k1=h*f(X,Y);
        k2=h*f(X+2*h/3,Y+2*k1/3);
        YY=Y+(k1+3*k2)/4;
        do
        {
            h=h/2;
            aux=YY;
            while(X<XX)
            {
                k1=h*f(X,Y);
                k2=h*f(X+2*h/3,Y+2*k1/3);
                Y=Y+(k1+3*k2)/4;
                X=X+h;
            }
            YY=Y;X=x[i];Y=y[i];
        }while(fabs(YY-aux)>eps);
        y[i+1]=YY;
        printf("valoarea aproximativa a solutiei in %f este %f\n",XX,YY);
        i++;
    }while(i!=n);
    return 0;
}
