public class Solution {
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
    	int ans = 0, idx = 0;
    	HashMap<Character, Integer> freq = new HashMap<Character, Integer>();
    	for (int i=0; i<s.length(); i++) {
    		char ch = s.charAt(i);
    		if (freq.containsKey(ch)) {
    			freq.put(ch, freq.get(ch) + 1);
    		} else {
    			freq.put(ch, 1);
    		}
    		if (freq.size() <= k) {
    			ans = Math.max(ans, i - idx + 1);
    		} else {
    			while (freq.size() > k) {
    				char ch1 = s.charAt(idx);
    				if (freq.get(ch1) == 1) {
    					freq.remove(ch1);
    				} else {
    					freq.put(ch1, freq.get(ch1) - 1);
    				}
    				++idx;
    			}
    		}
     	}
     	return ans;
    }
}
