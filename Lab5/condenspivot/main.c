#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    float a[10][10],aux,det;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%f",&a[i][j]);
    det=1;
    do
    {
        if(a[1][1]==0)
        {
            i=2;
            while((i<=n) && (a[i][1]==0))
                i++;
            if(i>n)
            {
                printf("det(A)=0");
                return 0;
            }
            for(j=1;j<=n;j++)
            {
                aux=a[1][j];
                a[1][j]=a[i][j];
                a[i][j]=aux;
            }
            det=det*(-1);
        }
        for(i=1;i<=n-2;i++)
            det*=a[1][1];
        for(i=2;i<=n;i++)
            for(j=2;j<=n;j++)
                a[i][j]=a[i][j]*a[1][1]-a[i][1]*a[1][j];
        n--;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=a[i+1][j+1];
    }while(n!=1);
    det=a[1][1]/det;
    printf("det(A)=%f",det);
    return 0;
}
