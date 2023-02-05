def computeLPSArray(pat, M, lps):
    len = 0 # length of the previous longest prefix suffix

    lps[0] # lps[0] is always 0
    i = 1

    # the loop calculates lps[i] for i = 1 to M-1
    while i < M:
        if pat[i]== pat[len]:
            len += 1
            lps[i] = len
            i += 1
        else:
            # This is tricky. Consider the example.
            # AAACAAAA and i = 7. The idea is similar
            # to search step.
            if len != 0:
                len = lps[len-1]

                # Also, note that we do not increment i here
            else:
                lps[i] = 0
                i += 1

# Python program for KMP Algorithm
def KMPSearch(pat, txt):
    M = len(pat)
    N = len(txt)

    # create lps[] that will hold the longest prefix suffix
    # values for pattern
    lps = [0]*M
    j = 0 # index for pat[]

    # Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps)

    i = 0 # index for txt[]
    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1

        if j == M:
            return i-j
            j = lps[j-1]
            #print ("Found pattern at index " + str(i-j))

        # mismatch after j matches
        elif i < N and pat[j] != txt[i]:
            # Do not match lps[0..lps[j-1]] characters,
            # they will match anyway
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
    return -1


# This code is contributed by Bhavya Jain



def two_six_count(D):
    s = str(D)
    return s.count("2")+s.count("6")



def solve(A,T):
    origin = [str(two_six_count(x)) for x in range(A,A+T)]
# 555 12345678
# 9
    pat = "".join(origin)
    maxx = 10**9
    count = 7
    control = (A+T)*10**7
    if control > maxx:
        control = maxx
    notorigin = [str(two_six_count(x)) for x in range(A+1, control)]
    while True:
        txt = "".join(notorigin)
        a = KMPSearch(pat, txt)
        if a == -1:
            print(count)
            control = (A+T)*10**2
            if control > maxx:
                control = maxx
            notorigin += [str(two_six_count(x)) for x in range((A+1)*10**count, control)]
            count += 1
        else:
            print(a+A+1)
            break


list = list(map(int, input().split()))

A = list[0]
T = list[1]

solve(A,T)