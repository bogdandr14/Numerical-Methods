#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f1(float x, float y)
{
    return sqrt(x * y - y * y);
}
float f2(float x, float y)
{
    return sqrt(y) / (sqrt(x) * (1 + x * y));
}
int main()
{
    float x1, x2, x3, y1, y2, y3, l1, l2, l3, p, S, I;
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);
    l1 = sqrt ( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) );
    l2 = sqrt ( (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3) );
    l3 = sqrt ( (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) );
    p = (l1 + l2 + l3) /2;
    S = sqrt(p * (p - l1) * (p - l2) * (p - l3) );
    I = S /12 * ( f2(x1, y1) + f2(x2, y2) + f2(x3, y3) + 9 * f2( (x1 + x2 + x3) /3, (y1 + y2 + y3) /3) );
    printf("Valoarea integralei este %f",I);
    return 0;
}
