#User function Template for python3

class Solution:
    def is_bleak(self, N):
        x = int(N).bit_length()  # Calculate the number of bits in N
        for i in range(1, x + 1):
            y = N - i
            c = 0
            while y > 0:
                y = y & (y - 1)
                c += 1
            if c == i:
                return 0
        return 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution();
		ans = ob.is_bleak(n)
		print(ans)

# } Driver Code Ends