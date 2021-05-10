class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for (auto i : s) freq[i]++;
        priority_queue<pair<int, char> > pq;
        for (auto i : s) {
            pq.push(make_pair(freq[i], i));
        }
        string ans = "";
        while (!pq.empty()) {
            pair<int, char> curr = pq.top(); pq.pop();
            ans += curr.second;
        }
        return ans;
    }
};