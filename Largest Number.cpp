class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> vec;
        for (auto i : nums) vec.push_back(to_string(i));
        sort(vec.begin(), vec.end(), [] (const string &a, const string &b) {
            return a + b > b + a;
        });
        for (auto i : vec) ans += i;
        return ans[0] == '0' ? "0" : ans;
    }
};