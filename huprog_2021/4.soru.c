#include<stdio.h>
#include<stdlib.h>
int main()
{
    int ogunSayisi, kapSayisi, sorguAraligi, i, j;
    int first, gram, sorgu;
    int dokulenMama;
    unsigned long total;
    scanf("%d %d %d", &ogunSayisi, &kapSayisi, &sorguAraligi);

    unsigned long* ikinci_satir;
    ikinci_satir = (unsigned long*) malloc(kapSayisi * sizeof(unsigned long));

    for ( i = 0; i < kapSayisi; i++)
    {
        scanf("%lu ", &ikinci_satir[i]);
    }    

    for ( j = 0; j < ogunSayisi; j++)
    {
        scanf("%d %d %d", &first, &gram, &sorgu);
        first --;
        sorgu --;
        dokulenMama = 1;
        total = 0;

        while (gram > dokulenMama)
        {
            ikinci_satir[first] += dokulenMama;
            gram -= dokulenMama;
            first += 1;
            dokulenMama += 1;
            if (first > kapSayisi-1){
                first = 0;
            }
        }
        ikinci_satir[first] += gram;

        for ( i = 0; i < sorguAraligi; i++)
        {
            total += ikinci_satir[sorgu];
            if (sorgu == kapSayisi-1)
                break;
            sorgu += 1;
        }
        printf("%lu ", total);
    }
    free(ikinci_satir);
    return 0;
}