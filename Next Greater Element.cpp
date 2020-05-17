void findNextGreaterElements (vector<int> arr) {
	stack<int> st;
	st.push(arr[0]);
	for (int i=1; i<arr.size(); i++) {
		if (st.empty()) st.push(arr[i]);
		else {
			while (!st.empty() && st.top() < arr[i]) {
				cout << "Next greater element for: " << st.top() << " is " << arr[i] << "\n";
				st.pop();
			}
			st.push(arr[i]);
		}
	}
	while (!st.empty()) {
		cout << st.top() << " does not have a next greater element\n";
		st.pop();
	}
}