class Solution {
public:
    unordered_map<string, vector<string> > memo;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if (memo.count(s)) {
            return memo[s];
        }
        for (auto word : wordDict) {
            if (s.substr(0, word.size()) == word) {
                if (s.size() == word.size()) {
                    res.push_back(word);
                } else {
                    vector<string> temp = wordBreak(s.substr(word.size()), wordDict);
                    for (auto resWord : temp) {
                        res.push_back(word + " " + resWord);
                    }
                }
            }
        }
        return memo[s] = res;
    }
};