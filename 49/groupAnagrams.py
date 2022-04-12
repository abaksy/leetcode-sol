from typing import List
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = dict()
        for string in strs:
            s = ''.join(sorted(string))
            if s not in result:
                result[s] = [string]
            else:
                result[s].append(string)
        return list(result.values())
