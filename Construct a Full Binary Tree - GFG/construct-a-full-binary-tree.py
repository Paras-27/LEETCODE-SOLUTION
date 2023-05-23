#User function Template for python3

class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None


class Solution:
    def constructBinaryTree(self, pre, preM, n):
        self.i = 0
        return self.util(pre, preM, n)
    
    def util(self, pre, preM, n):
        if self.i == n:
            return None
        j = 0
        while j < n:
            if preM[j] == pre[self.i]:
                break
            j += 1
        preM[j] = -1
        root = Node(pre[self.i])
        self.i += 1
        if j == n - 1 or preM[j + 1] == -1:
            return root
        root.left = self.util(pre, preM, n)
        root.right = self.util(pre, preM, n)
        return root


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    
    def printInorder(node):
        if node == None:
            return
        printInorder(node.left)
        print(node.data, end = " ")
        printInorder(node.right)
        
    test_cases = int(input())
    for _ in range (test_cases):
        N = int(input())
        pre = list(map(int, input().split()))
        preMirror = list(map(int, input().split()))
        res = Solution().constructBinaryTree(pre, preMirror, N)
        if printInorder(res) != None:
            print(printInorder(res)[:len(printInorder(res))-2])
        print()
# } Driver Code Ends