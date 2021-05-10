class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umii;
        vector<int> vec;
        for (size_t i=0; i<nums.size(); i++) {
            int next = nums[i];
            if (umii.count(next)) {
                vec.push_back(umii[next]);
                vec.push_back(i);
                goto outer;
            }
            else umii[target - next] = i;
        }
        outer:
        return vec;
    }
};