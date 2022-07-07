#include <stdio.h>
#include <stdlib.h>
float f(float x, float y)
{
    return 2*y/x;
}
int main()
{
    int i,n;
    float x[20],y[20],X,Y,XX,YY,eps,h,aux;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
        scanf("%f",&x[i]);
    scanf("%f%f",&y[0],&eps);
    i=0;
    do
    {
        X=x[i];
        XX=x[i+1];
        Y=y[i];
        h=XX-X;
        YY=Y+h*f(X,Y);
        do
        {
            h=h/2;
            aux=YY;
            while(X<XX)
            {
                Y=Y+h*f(X,Y);
                X=X+h;
            }
            YY=Y;X=x[i];Y=y[i];
        }
        while(fabs(YY-aux)>eps);
        y[i+1]=YY;
        printf("Valoarea aproximativa a solutiei in %f este %f\n",XX,YY);
        i++;
    }
    while(i!=n);
    return 0;
}
