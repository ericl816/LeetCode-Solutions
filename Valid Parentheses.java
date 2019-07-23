class Solution {
    public boolean isValid (String sequence) {
        Stack<Character> st = new Stack<Character>();
        for (int i=0; i<sequence.length(); i++) {
            char next = sequence.charAt(i);
            if (next == '(') st.push(next);
            else if (next == ')') {
              if (st.isEmpty() || (st.peek() != '(')) {
                return false;
              }
              else st.pop();
            }
            if (next == '[') st.push(next);
            else if (next == ']') {
              if (st.isEmpty() || (st.peek() != '[')) {
                return false;
              }
              else st.pop();
            }
            if (next == '{') st.push(next);
            else if (next == '}') {
              if (st.isEmpty() || (st.peek() != '{')) {
                return false;
              }
              else st.pop();
            }
        }
        return st.isEmpty();
    }
}