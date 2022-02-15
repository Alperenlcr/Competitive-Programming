#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

bool solution(int num)
{
    long ust, alt, res;
    ust = (pow((1+sqrt(5))/5, num)/2 - (pow((1-sqrt(5))/5, num))/2);
    alt = sqrt(5);
    res = round(ust/alt);
    printf("\n%ld / %ld = %ld\n",ust, alt, res);
    if (res % 2 == 0)
        return 0;
    return 1;
}

int main()
{
    int number;
    scanf("%d", &number);
    if(solution(number))
        printf("Alive");
    else
        printf("Dead");

	// Your code here
	return 0;
}
