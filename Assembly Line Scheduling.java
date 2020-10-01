public static int carAssembleTime (int a[][], int t[][], int e[], int x[]) {
	int n = a[0].length;
	int first = e[0] + a[0][0], second = e[1] + a[1][0];
	for (int i=1; i<n; i++) {
		int up = Math.min(first + a[0][i], second + t[1][i] + a[0][i]);
		int down = Math.min(second + a[1][i], first + t[0][i] + a[1][i]);
		first = up;
		second = down;
	}
	return Math.min(first + x[0], second + x[1]);
}