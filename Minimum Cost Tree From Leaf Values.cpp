class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> st;
        st.push_back(0x3f3f3f3f);
        int ans = 0;
        for (auto i : arr) {
            while (st.back() <= i) {
                int node = st.back();
                st.pop_back();
                // node = parent of 2 leaf nodes, st.back() & i = left and right leaf nodes
                ans += node * min(st.back(), i);
            }
            st.push_back(i);
        }
        while (st.size() > 2) {
            int res = st.back();
            st.pop_back();
            ans += res * st.back();
        }
        return ans;
    }
};