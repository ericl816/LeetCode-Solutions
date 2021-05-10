class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        sum_a = sum(A)
        sum_b = sum(B)
        diff = (sum_b - sum_a) // 2
        s = set(B)
        for i in s:
            if i - diff in A:
                return [i - diff, i]
        return [-1, -1]