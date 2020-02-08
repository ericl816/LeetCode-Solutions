class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        lo = 0
        hi = len(nums) - 1
        while lo < hi:
            mid = (lo + hi) >> 1
            if nums[mid] > nums[mid + 1]:
                return nums[mid + 1]
            if nums[mid] > nums[hi]:
                lo = mid + 1
            elif nums[mid] <= nums[hi]:
                hi = mid
        return nums[0]
        