class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int lo = 0, hi = height.size() - 1, maxl = 0, maxr = 0, ans = 0;
        while (lo < hi) {
            if (height[lo] < height[hi]) {
                if (height[lo] >= maxl) maxl = height[lo];
                else ans += maxl - height[lo];
                lo++;
            }
            else {
                if (height[hi] >= maxr) maxr = height[hi];
                else ans += maxr - height[hi];
                hi--;
            }
        }
        return ans;
    }
};