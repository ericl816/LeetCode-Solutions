class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        String [] tokens = sentence.split(" ");
        HashSet<String> ss = new HashSet<String>();
        for (String i : dict) ss.add(i);
        for (int i=0; i<tokens.length; i++) {
            for (int j=1; j<tokens[i].length(); j++) {
                if (ss.contains(tokens[i].substring(0, j))) {
                    tokens[i] = tokens[i].substring(0, j);
                }
            }
        }
        String ans = "";
        for (String i : tokens) ans += i + " ";
        ans = ans.substring(0, ans.length() - 1);
        return ans;
    }
}