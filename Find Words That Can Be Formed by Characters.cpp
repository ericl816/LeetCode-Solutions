class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if (words.empty()) return 0;
        map<char, int> freq1;
        for (auto i : chars) freq1[i]++;
        int ans = 0;
        for (auto i : words) {
            map<char, int> freq2;
            for (auto j : i) freq2[j]++;
            bool flag = 1;
            for (auto j : i) {
                if (freq2[j] == 0 || freq2[j] > freq1[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ans += i.size();
        }
        return ans;
    }
};