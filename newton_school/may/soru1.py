from math import sqrt
def solution(num):
    num -= 1
    ust = pow((1+sqrt(5))/2, num)
    alt = sqrt(5)
    res = round(ust/alt)
    #print("\n%ld / %ld = %ld\n",ust, alt, res)
    if res % 2 == 0:
        return False
    return True


number = int(input())
if(solution(number)):
    print("Alive")
else:
    print("Dead")

