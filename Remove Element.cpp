class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto i : nums) {
            if (i == val) {
                nums.erase(remove(nums.begin(), nums.end(), i), nums.end());
            }
        }
        return nums.size();
    }
};