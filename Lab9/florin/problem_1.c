#include <stdio.h>
#include <stdlib.h>
void pag(int n)
{
    int k,a,nrpag,sa=0;
    k=1;///numarul de cifre al paginii
    a=9;///numarul de pagini cu k cifre
    while(n>0)///continua pana cand numarul de cifre a fost utilizat
    {
        sa=sa+a;///aduna numarul de pagini la sa
        n=n-a*k;///scade numarul de cifre utilizat pentru a creea cele a pagini
        a=a*10;///creste numarul de pagini odata cu cresterea numarului de cifre
        k=k+1;///creste numarul de cifre al paginilor
    }
    a=a/10;///scade numarul de pagini
    k--;///decrementeeaza numarul de cifre
     n=n+a*k;///aduna la n cifrele ultimului set de pagini care nu a putut fi creat complet
     sa=sa-a;///scade numarul de pagini care nu au putut fi create complet
     nrpag=n/k+sa;///numarul de pagini este reprezentat de sa si partea intraga a restului de cifre nefolosite
     printf("Numarul de pagini este %d",nrpag);
}
