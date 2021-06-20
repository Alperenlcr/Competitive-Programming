"""
class Solution:
    def sortSentence(self, s: str):
        r = ""
        s_dizi = s.split(" ")
        for i in range(len(s_dizi)+1):
            for j in s_dizi:
                if int(j[-1]) == i:
                    r += j[:-1]+" "
        return r[:-1]
a = Solution()
print(a.sortSentence("Myself2 Me1 I4 and3"))
"""
"""
class Solution:
    def memLeak(self, memory1: int, memory2: int):
        i = 1
        while memory1-i>=0 or memory2-i>=0:
            if memory1>=memory2:
                memory1 -= i
            else:
                memory2 -= i
            i+=1
        return [i, memory1, memory2]
a  = Solution()
print(a.memLeak(8,11))
"""
"""
class Solution:
    def rotateTheBox(self, box):
        n = len(box)
        m = len(box[0])
        for i in range(n):
            x = ("".join(box[i])).split("*")
            new = []
            for j in x:
                point = j.count(".")
                sharp = j.count("#")
                new.extend(list("."*point + "#"*sharp))
                new.append("*")
            new.pop()
            box[i] = new

        new_box = [[""]*n for i in range(m)]
        for i in range(n):
            for j in range(m):
                new_box[j][n-1-i] = box[i][j]

        return new_box
a = Solution()
x = [ ["#","#","*",".","*","."], ["#","#","#","*",".","."], ["#","#","#",".","#","."] ]

y = a.rotateTheBox(x)
for i in x:
    print(i)
print()
for i in y:
    print(i)
"""
"""
class Solution:
    def sumOfFlooredPairs(self, nums):
        sum = 0
        nums = sorted(nums)
        l = len(nums)
        for i in range(l):
            x = i
            while x != 0 and nums[i] == nums[x]:
                x -= 1
            if x != 0:
                x += 1
            for j in range(x,l):
                temp = nums[j]//nums[i]
                if temp > 0:
                    # print(nums[j],nums[i])
                    print(j, i)
                    sum += temp
        return sum

a = Solution()
print(a.sumOfFlooredPairs([5,5,5,5,5,5]))
"""
