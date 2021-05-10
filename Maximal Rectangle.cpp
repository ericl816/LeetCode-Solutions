class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        if (n == 0) return 0;
        vector<vector<int>> vert_dp(m, vector<int>(n)); // height of vertical segment whose bottom point is [i][j]
        for (int j = 0; j < n; j++){
            vert_dp[0][j] = (matrix[0][j] == '1');
            for (int i = 1; i < m; i++){
                vert_dp[i][j] = (matrix[i][j] == '1') ? vert_dp[i-1][j]+1 : 0;
            }
        }
        
        int cur_max = 0;
        for (int i = 0; i < m; i++){
            cur_max = max(cur_max, largestRectangleArea(vert_dp[i]));
        }
        
        return cur_max;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        if(heights.size()==0)return 0;
        int ans = heights[0];
        int n = heights.size();
        int i = 0;
        int tp = 0;
        while(i<n) {
            if(s.empty() || heights[s.top()] <= heights[i]) { // ensure the heights in stack is ascending
                s.push(i++);
                //cout << s.top()  << ": " << heights[s.top()] << endl;
            } else { // drive out all the previous heights that is greater than heights[i]
                tp = s.top();
                s.pop();
                ans = max(ans, heights[tp] * (s.empty()?i: i - s.top() - 1)); 
                // indexes from s.top() to i-1, because heights[i-1] >= s.top()
            }
        }
        
        while(!s.empty()) {
            tp = s.top();
            s.pop();
            ans = max(ans,heights[tp] *  (s.empty()?i: i - s.top() - 1));
        }
        return ans;
    }
};