class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        max_open, min_open = 0, 0
        for c in s:
            min_open = min_open + 1 if c == '(' else min_open - 1
            max_open = max_open + 1 if c != ')' else max_open - 1
            if max_open < 0: return False
            min_open = max(0, min_open)
        return min_open == 0