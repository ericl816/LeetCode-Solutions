class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, l = 1, r = height.size();
        while (l < r) {
            int minn = min(height[l - 1], height[r - 1]);
            ans = max(ans, (r - l) * minn);
            while (height[l - 1] <= minn && l < r) l++;
            while (height[r - 1] <= minn && l < r) r--;
        }
        return ans;
    }
};