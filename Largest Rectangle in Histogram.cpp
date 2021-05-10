class Solution {
public:
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