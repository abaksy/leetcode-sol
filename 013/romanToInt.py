class Solution:
    def romanToInt(self, s: str) -> int:
        total = 0
        mapping = {
            'I': 1, 
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        for i in range(len(s)):
            curr = mapping[s[i]]
            prev = mapping[s[i-1]] if i >= 1 else 0
            if i >= 1 and curr > prev:
                total += curr - (2*prev)
            else:
                total += curr
        return total
        