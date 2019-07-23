class Solution {
public:
    int longestWPI(vector<int>& hours) {
    	map<int, int> dict;
    	dict[0] = -1;
    	int ans = 0, cnt = 0;
    	for (int i=0; i<hours.size(); i++) {
    		cnt += hours[i] > 8 ? -1 : 1;
    		map<int, int>::iterator it=dict.upper_bound(cnt);
    		if (it != dict.end()) ans = max(ans, i - it->second);
    		else dict.insert({cnt, i});
    	}
    	return ans;
    }
};