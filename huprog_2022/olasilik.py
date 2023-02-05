# Python3 implementation of the approach

# Function to return the factorial
# of a number
def factorial(f):
	fact = 1
	for i in range(2, f + 1):
		fact *= i
	return fact

# Function to return the count of distinct
# (N + M) digit numbers having N 0's
# and and M 1's with no leading zeros
def findPermuatation(N, M):
	permutation = (factorial(N + M - 1) //
				(factorial(N) * factorial(M - 1)))
	return permutation


# Driver code

n = int(input())

for i in range(n):
    sum = 0.000000
    k = 1
    distance = int(input())

    for j in range(distance-2,0,-2):

        sum += (pow(0.5,(j+k))*findPermuatation(j+1, k))
        k += 1
    if distance%2 == 0:
        sum += pow(0.5,k)

    print("{:.6f}".format(sum))