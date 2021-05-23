class Solution {
public:
    string reorganizeString(string s) {
        if (s.empty()) {
            return "";
        }
        priority_queue<pair<int, char> > pq;
        map<char, int> freq;
        for (auto ch : s) {
            ++freq[ch];
        }
        for (int i=0; i<26; i++) {
            if (freq[i + 'a'] > 0) {
                pq.push(make_pair(freq[i + 'a'], i + 'a'));
            }
        }
        pair<int, char> prev = make_pair(0, 'a');
        string ans = "";
        while (!pq.empty()) {
            pair<int, char> curr = prev;
            prev = pq.top();
            pq.pop();
            ans += prev.second;
            --prev.first;
            if (curr.first > 0) {
                pq.push(curr);
            }
        }
        if (prev.first > 0) {
            return "";
        }
        return ans;
    }
};
