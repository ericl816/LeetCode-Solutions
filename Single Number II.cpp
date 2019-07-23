class Solution {
public:
    // Not good with memory but still passes
    
    map<int, int> freq;
    
    int singleNumber(vector<int>& nums) {
        for (auto i : nums) freq[i]++;
        for (auto i : nums) {
            if (freq[i] != 3) {
                return i;
            }
        }
        return -1;
    }
};