class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
    	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    	if (nums.empty()) {
    		return -1;
    	}
    	sort(nums.begin(), nums.end());
    	for (auto num : nums) {
    		while (!pq.empty() && (pq.top().first + 1 < num || pq.top().second == k)) {
    			if (pq.top().second != k) {
    				return false;
    			}
    			pq.pop();
    		}
    		if (pq.empty() || pq.top().first == num) {
    			pq.push(make_pair(num, 1));
    			continue;
    		}
    		int freq = pq.top().second + 1;
    		pq.pop();
    		pq.push(make_pair(num, freq));
    	}
    	while (!pq.empty()) {
    		if (pq.top().second != k) {
    			return 0;
    		}
    		pq.pop();
    	}
    	return 1;
    }
};