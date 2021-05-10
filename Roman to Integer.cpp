class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int ans = 0;
        for (size_t i=0; i<s.size(); i++) {
            int curr = dict[s[i]], next = dict[s[i + 1]];
            if (curr < next) ans -= curr;
            else ans += curr;
        }
        return ans;
    }
};