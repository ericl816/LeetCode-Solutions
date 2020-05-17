// T: O(N)
// S: O(N)
vector<int> calculateSpan (vector<int> prices) {
	vector<int> ans;
	if (prices.empty()) return ans;
	stack<int> st;
	st.push(0);
	ans.push_back(1);
	for (int i=1; i<prices.size(); i++) {
		while (!st.empty() && prices[st.top()] <= prices[i]) st.pop();
		if (st.empty()) ans.push_back(i + 1);
		else ans.push_back(i - st.top());
		st.push(i);
	}
	return ans;
}

// T: O(N)
// S: O(1)
vector<int> calculateSpanOptimized (vector<int> prices) {
	vector<int> ans;
	if (prices.empty()) return ans;
	ans.push_back(1);
	for (int i=1; i<prices.size(); i++) {
		int cnt = 1;
		while (i >= cnt && prices[i] >= prices[i - cnt]) cnt += ans[i - cnt];
		ans.push_back(cnt);
	}
	return ans;
}