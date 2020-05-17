// T: O(maxx^2)
// S: O(N)
bool checkTriplet (vector<int> &arr) {
	int maxx = 0;
	unordered_map<int, int> dict;
	for (auto i : arr) {
		dict[i]++;
		maxx = max(maxx, i);
	}
	for (int i=1; i<=maxx; i++) {
		if (!dict[i]) continue;
		for (int j=1; j<=maxx; j++) {
			if (!dict[j] || (i == j && dict[j] == 1)) continue;
			int res = sqrt(i * i + j * j);
			if (res > maxx) continue;
			if (res * res ^ i * i + j * j) continue;
			if (dict[res]) return 1;
		}
	}
	return 0;
}

// T: O(N^2)
// S: O(1)

bool checkTriplet1 (vector<int> &arr) {
	for (int i=0; i<arr.size(); i++) arr[i] *= arr[i];
	sort(arr.begin(), arr.end());
	for (int i=arr.size() - 1; i>=0; i--) {
		int l = 0, r = arr.size() - 1;
		while (l < r) {
			if (arr[l] + arr[r] == arr[i]) return 1;
			else if (arr[l] + arr[r] < arr[i]) l++;
			else r--;
		}
	}
	return 0;
}