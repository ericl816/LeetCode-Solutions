class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int> > q;
        set<string> s;
        for (auto i : wordList) s.insert(i);
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            pair<string, int> curr = q.front();
            q.pop();
            if (curr.first == endWord) return curr.second;
            for (size_t i=0; i<curr.first.size(); i++) {
                for (char j='a'; j<='z'; j++) {
                    char temp = curr.first[i];
                    if (curr.first[i] != j) curr.first[i] = j;
                    if (s.find(curr.first) != s.end()) {
                        q.push(make_pair(curr.first, curr.second + 1));
                        s.erase(curr.first);
                    }
                    curr.first[i] = temp;
                }
            }
        }
        return 0;
    }
};