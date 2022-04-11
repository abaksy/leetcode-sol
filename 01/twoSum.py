from typing import List

class Solution:
    '''
    Using sorting and two pointers.
    Sort the input array.
    Have two pointers `i` and `j` (`i` at the beginning, `j` at the end of input array).
    If sum of `i` and `j` is higher than target, move `j` down, else if 
    sum is less than target, move `i` up
    else return indices of elements at `i` and `j`
    '''
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        idx_nums = [(i, nums[i]) for i in range(n)]         # Create array with original index added
        idx_nums = sorted(idx_nums, key = lambda x: x[1])
        i, j = 0, n-1
        while i <= j:
            ss = idx_nums[i][1] + idx_nums[j][1]
            if ss == target:
                return [idx_nums[i][0], idx_nums[j][0]]
            elif ss > target:
                j -= 1
            else:
                i += 1
                