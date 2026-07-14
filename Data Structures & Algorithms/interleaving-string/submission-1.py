from typing import List

class Solution:
    def helper(self, i: int, j: int, m: int, n: int, s1: str, s2: str, s3: str, dp: List[List[int]]) -> bool:
        if i == m and j == n:
            return True

        if dp[i][j] != -1:
            return dp[i][j]
        case1 = False
        case2 = False

        if i < m and s1[i] == s3[i + j]:
            case1 = self.helper(i + 1, j, m, n, s1, s2, s3, dp)

        if j < n and s2[j] == s3[i + j]:
            case2 = self.helper(i, j + 1, m, n, s1, s2, s3, dp)

        dp[i][j] = 1 if (case1 or case2) else 0
        return dp[i][j] == 1

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        i = 0
        j = 0
        m = len(s1)
        n = len(s2)
         # Initialize (m+1) x (n+1) matrix with -1
        dp = [[-1 for _ in range(n+1)] for _ in range(m+1)]
        if m + n != len(s3):  
            return False

        return self.helper(i, j, m, n, s1, s2, s3, dp)