class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> freq;
        for (auto i : A) {
            for (auto j : B) {
                freq[i + j]++;
            }
        }
        int ans = 0;
        for (auto i : C) {
            for (auto j : D) {
                if (freq.count(-i - j)) ans += freq[-i - j];
            }
        }
        return ans;
    }
};