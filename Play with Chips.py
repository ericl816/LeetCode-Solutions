class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        if len(chips) == 0: return 0
        odd = sum(1 if i % 2 == 1 else 0 for i in chips)
        return min(odd, len(chips) - odd)