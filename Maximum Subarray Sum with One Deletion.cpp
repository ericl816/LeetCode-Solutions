class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> DP1(arr.size() + 1, -0x3f3f3f3f), DP2(arr.size() + 1, -0x3f3f3f3f);
        int ans = -0x3f3f3f3f;
        for (int i=0; i<arr.size(); i++) ans = max(ans, arr[i]);
        for (int i=0; i<arr.size(); i++) {
            DP1[i] = max(DP1[i], arr[i]);
            if (i > 0) {
                DP1[i] = max(DP1[i], DP1[i - 1] + arr[i]);
                DP2[i] = max(DP2[i], max(DP1[i - 1], DP2[i - 1] + arr[i]));
            }
            ans = max(ans, max(DP1[i], DP2[i]));
        }
        return ans;
    }
};