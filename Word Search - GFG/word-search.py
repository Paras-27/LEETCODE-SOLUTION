class Solution:
    def helper(self, x, y, row, col, board, direction, word, pos, present):

        if present+board[x][y]==word:
            self.found=True
            return
        
        temp, board[x][y] = board[x][y], -1
        
        for x2, y2 in direction:
            x1, y1 = x+x2, y+y2
            if -1<x1<row and -1<y1<col and board[x1][y1]==word[pos+1]:
                self.helper(x1, y1, row, col, board, direction, word, pos+1, present+temp)
        
        board[x][y] = temp

    def isWordExist(self, board, word):
        row, col, direction, self.found = len(board), len(board[0]), [[0, -1], [-1, 0], [0, 1], [1, 0]], False

        for i in range(row):
            for j in range(col):
                if self.found: return True
                elif board[i][j]==word[0]:
                    self.helper(i, j, row, col, board, direction, word, 0, "")
        
        return self.found


#{ 
 # Driver Code Starts
if __name__ == '__main__':
	T=int(input())
	for tt in range(T):
		n, m = map(int, input().split())
		board = []
		for i in range(n):
			a = list(input().strip().split())
			b = []
			for j in range(m):
				b.append(a[j][0])
			board.append(b)
		word = input().strip()
		obj = Solution()
		ans = obj.isWordExist(board, word)
		if(ans):
			print("1")
		else:
			print("0")

# } Driver Code Ends