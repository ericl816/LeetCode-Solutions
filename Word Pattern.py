class Solution:
    def wordPattern(self, pattern: str, string: str) -> bool:
        lst = string.split(' ')
        if len(pattern) != len(lst):
            return False
        hash_map = {}
        for i in range(len(pattern)):
            if not hash_map.get(pattern[i], 0):
                if lst[i] in hash_map.values():
                    return False
                hash_map[pattern[i]] = lst[i]
            if hash_map[pattern[i]] != lst[i]:
                return False
        return True