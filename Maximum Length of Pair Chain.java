class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (int a[], int b[]) -> a[0] - b[0]);
        int c = Integer.MIN_VALUE, ans = 0;
        for (int [] next : pairs) {
            if (next[1] < c) c = next[1];
            if (next[0] > c) {
                c = next[1];
                ans++;
            }
        }
        return ans;
    }
}