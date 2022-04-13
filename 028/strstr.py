class Solution:
    def badCharHeuristic(self, string, length):
        last_occurrence = [-1]*256
        for i in range(length):
            last_occurrence[ord(string[i])] = i
        return last_occurrence
        
    def strStr(self, haystack: str, needle: str) -> int:
        if needle is None or needle == "":
            return 0
        m = len(needle)
        n = len(haystack)
        if m > n:
            return -1
        
        badChar = self.badCharHeuristic(needle, m)
        s = 0
        found = False
        while(s <= n-m):
            j = m-1
            while j >= 0 and needle[j] == haystack[s + j]:
                j -= 1       
            if j < 0:
                found = True
                return s
            else:
                s += max(1, j - badChar[ord(haystack[s+j])])
        if not found:
            return -1
