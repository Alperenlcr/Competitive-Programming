class node:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.preIndex = 0
        self.posIndex = 0

    def generate_binary_tree(self, pre, post):
        root = node(pre[self.preIndex])
        self.preIndex += 1
        if (root.val != post[self.posIndex]):
            root.left = self.generate_binary_tree(pre, post)
        if (root.val != post[self.posIndex]):
            root.right = self.generate_binary_tree(pre, post)
        self.posIndex += 1
        return root

    def find_inorder(self, root):
        if root is None:
            return []
        inorder = []
        inorder.extend(self.find_inorder(root.left))
        inorder.append(root.val)
        inorder.extend(self.find_inorder(root.right))
        return inorder

q = int(input())
count = 0
lists = []
for i in range(q):
    lists.append(list(map(int, input().split())))
for i in range(len(lists)):
    for j in range(len(lists)):
        if len(lists[i]) == len(lists[j]) and sorted(list(set(lists[i]))) == sorted(list(set(lists[j]))):
            try:
                s = Solution()
                t = s.generate_binary_tree(lists[i], lists[j])
                inorder = s.find_inorder(t)
                if sorted(list(set(lists[i]))) == sorted(list(set(inorder))):
                    # print(lists[i], lists[j], ' -> ', inorder)
                    count += 1
            except IndexError:
                pass
print(count)

"""
9
88 80 14
1 3 5 4 2
29 100 68 66 27 13 35
71 36 79 42 20
58 59 22 78 12
4 1 3 2 5
9 93 98 97 91 94
1 2 5 3 4
2 1 4 3 5

"""