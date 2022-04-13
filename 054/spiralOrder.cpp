#include<algorithm>
#include<vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> spiral_order;
        int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        int dir = 1;  // 1 means left to right, 
        int i = 0;
        while(top <= bottom && left <= right)
        {
            if(dir == 1)  //left to right
            {
                for(i = left; i<= right; ++i)
                    spiral_order.push_back(matrix[top][i]);
                top++;
                dir = 2;
            }
            else if(dir == 2) //top to bottom
            {
                for(i = top; i<=bottom; ++i)
                    spiral_order.push_back(matrix[i][right]);
                right--;
                dir = 3;
            }
            else if(dir == 3) //right to left
            {
                for(i = right; i>= left; i--)
                    spiral_order.push_back(matrix[bottom][i]);
                bottom--;
                dir = 4;
            }
            else if(dir == 4) //bottom to top
            {
                for(i = bottom; i>=top; i--)
                    spiral_order.push_back(matrix[i][left]);
                left++;
                dir = 1;
            }
        }
        return spiral_order;
    }
};