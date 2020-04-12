class Solution {
public:
    int countElements(vector<int>& arr) {
        if (arr.empty()) return 0;
        int cnt = 0;
        set<int> s;
        for (auto i : arr) s.insert(i);
        for (auto i : arr) {
            if (s.count(i + 1)) cnt++;
        }
        return cnt;
    }
};