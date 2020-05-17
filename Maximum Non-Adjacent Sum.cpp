int maxSum (vector<int> arr) {
	if (arr.empty()) return 0;
	int sum = 0, maxx_incl = arr[0], maxx_excl = 0;
	for (int i=1; i<arr.size(); i++) {
		int res = maxx_incl > maxx_excl ? maxx_incl : maxx_excl;
		maxx_incl = maxx_excl + arr[i];
		maxx_excl = res;
	}
	return maxx_incl > maxx_excl ? maxx_incl : maxx_excl;
}