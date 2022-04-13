class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {'}': '{', ')': '(', ']': '['}
        for ch in s:
            if ch in ['(', '{', '[']:
                stack.append(ch)
            else:
                if not stack:
                    return False
                elif not stack[-1] == mapping[ch]:
                    return False
                else:
                    stack.pop(-1)
        return len(stack) == 0