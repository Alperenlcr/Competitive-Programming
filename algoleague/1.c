#include<stdio.h>

int main()
{
    int q, l, r, k, c, count;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d %d", &l, &r, &k);
        c = 0;
        for (int sayi = l; sayi <= r; sayi++)
        {
            count = 0;
            for (int j = 1; j <= k; j++)
            {
                if (sayi%j==0)
                    count ++;
            }
            if (count==k && sayi%(k+1)!=0)
                c ++;
        }
        printf("%d\n", c);
    }
    
    return 0;
}