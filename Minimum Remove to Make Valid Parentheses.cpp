class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == ')') {
                if (!st.empty() && s[st.top()] == '(' && s[st.top()] != s[i]) st.pop();
                else st.push(i);
            }
        }
        while (!st.empty()) {
            s.erase(s.begin() + st.top());
            st.pop();
        }
        return s;
    }
};