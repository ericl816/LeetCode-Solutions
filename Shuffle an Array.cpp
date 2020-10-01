class Solution {
public:
    vector<int> orig, vec;
    Solution(vector<int>& nums) {
        orig = nums;
        vec = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec = orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i=0; i<vec.size(); i++) {
            int rand_idx = i + rand() % (vec.size() - i);
            swap(vec[i], vec[rand_idx]);
        }
        return vec;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */