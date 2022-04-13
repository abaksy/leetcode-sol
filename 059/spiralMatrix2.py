from typing import List

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        spiralMatrix = [[0 for _ in range(n)] for _ in range(n)]
        val = 1
        top = 0
        bottom = n-1
        left = 0
        right = n-1
        dirn = 1
        while val <= n*n:
            if dirn==1:    # Left to right
                for i in range(left, right+1):
                    spiralMatrix[top][i] = val
                    val += 1
                top += 1
                dirn = 2
            elif dirn == 2: # Top to bottom
                for i in range(top, bottom+1):
                    spiralMatrix[i][right] = val
                    val += 1
                right -= 1
                dirn = 3
            elif dirn == 3:     #Right to left
                for i in range(right, left-1, -1):
                    spiralMatrix[bottom][i] = val
                    val += 1
                bottom -= 1
                dirn = 4
            elif dirn == 4: # Bottom to top
                for i in range(bottom, top-1, -1):
                    spiralMatrix[i][left] = val
                    val += 1
                left += 1
                dirn = 1
        return spiralMatrix
