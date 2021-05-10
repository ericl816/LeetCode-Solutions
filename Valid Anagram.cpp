class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        if (s.size() != t.size()) return 0;
        for (auto i : s) freq[i]++;
        for (auto i : t) freq[i]--;
        for (auto i : t) {
            if (freq[i] != 0) return 0;
        }
        return 1;
    }
};