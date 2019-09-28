class Solution {
public:
    
    vector<int> PSA;
    
    Solution(vector<int>& w) {
        for (int i=1; i<w.size(); i++) w[i] += w[i - 1];
        PSA = w;
    }
    
    int pickIndex() {
        return upper_bound(PSA.begin(), PSA.end(), rand() % PSA.back()) - PSA.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */