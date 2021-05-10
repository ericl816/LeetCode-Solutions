class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) return 0;
        while (!stones.empty()) {
            sort(stones.begin(), stones.end());
            if (stones.size() >= 2) {
                int x = stones[stones.size() - 2], y = stones[stones.size() - 1];
                if (x == y) {
                    stones.pop_back();
                    stones.pop_back();
                } else {
                    int diff = y - x;
                    stones.pop_back();
                    stones.pop_back();
                    stones.push_back(diff);
                }
            } else if (stones.size() == 1) {
                return stones.back();
            }
        }
        return 0;
    }
};