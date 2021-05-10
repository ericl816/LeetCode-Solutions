class Solution {
    public String originalDigits(String s) {
        int[] table = new int[26];
        for (char c : s.toCharArray()) {
            table[c - 'a']++;
        }
        int[] temp = new int[10];
        char[] identifiers = new char[] {'z', 'w', 'u', 'f', 'o', 'x', 's', 'g', 't', 'i'};
        int[] indexes = new int[] {0, 2, 4, 5, 1, 6, 7, 8, 3, 9};
        String[] strs = new String[] {"zero", "two", "four", "five", "one", "six", "seven", "eight", "three", "nine"};
        for (int i = 0; i < 10; i++) {
            char iden = identifiers[i];
            int index = indexes[i];
            String str = strs[i];
            int fre = table[iden - 'a'];
            if (fre > 0) {
                temp[index] = fre;
                for (char c : str.toCharArray()) {
                    table[c - 'a'] -= fre;
                }
            }
        }
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < temp[i]; j++) {
                result.append(i);
            }
        }
        return result.toString();
    }
}