class Solution:
    def numOfSubarrays(self, A: List[int], k: int, threshold: int) -> int:
        prefix = [0]
        for x in A:
            prefix.append(prefix[-1] + x)
        ans = 0
        for i in range(len(prefix) - k):
            if prefix[i + k] - prefix[i] >= threshold * k:
                ans += 1
        return ans