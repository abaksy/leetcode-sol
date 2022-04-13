from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = []
        minLen = min([len(x) for x in strs])
        for i in range(minLen):
            iChar = [x[i] for x in strs]
            if len(set(iChar)) == 1:
                prefix.append(iChar[0])
            else:
                break
        return ''.join(prefix)
        