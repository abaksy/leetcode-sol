import itertools
class Solution:
    def compare(self, n1, n2):
        n1, n2 = int(n1), int(n2)
        if n1 > n2:
            return 1
        elif n1 == n2:
            return 0
        else:
            return -1
        
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        versions = [v1, v2]
        versions = zip(*itertools.zip_longest(*versions, fillvalue = "0"))
        v1, v2 = list(versions)
        for i in range(len(v1)):
            res = self.compare(v1[i], v2[i])
            if res != 0:
                return res
            else:
                continue
        if res == 0:
            return 0
        