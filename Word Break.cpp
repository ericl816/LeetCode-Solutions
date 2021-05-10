class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> DP(s.size() + 1, 0);
        DP[0] = 1;
        set<string> setDict;
        for (auto i : wordDict) {
            setDict.insert(i);
        }
        for (int i=1; i<=s.size(); i++) {
            for (int j=0; j<i; j++) {
                if (setDict.count(s.substr(j, i - j)) && DP[j]) {
                    DP[i] = 1;
                    break;
                }
            }
        }
        return DP[s.size()];
    }
};