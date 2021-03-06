class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    
    void reverse (vector<int> &arr, int lo, int hi) {
        while (lo < hi) swap(arr[lo++], arr[hi--]);
    }
};
