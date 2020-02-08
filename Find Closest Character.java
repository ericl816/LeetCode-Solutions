import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'closest' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. STRING s
     *  2. INTEGER_ARRAY queries
     */

    // Preprocess everything
    public static List<Integer> preprocess(String s) {
        List<Integer> result = new ArrayList<>();
        // Preprocess starting from leftmost index
        HashMap<Integer, Integer> dictFront = new HashMap<>();
        HashMap<Character, Integer> seenFront = new HashMap<>();
        for(int i = 0; i<s.length();i++){
            Character c = s.charAt(i);
            int distance = -1;
            if(seenFront.containsKey(c)){
                distance = i - seenFront.get(c);
            }
            seenFront.put(c,i);
            dictFront.put(i, distance);
        }

        // Preprocess starting from rightmost index
        HashMap<Integer, Integer> dictBack = new HashMap<>();
        HashMap<Character, Integer> seenBack = new HashMap<>();
        for(int i = s.length()-1; i >= 0;i--){
            Character c = s.charAt(i);
            int distance = -1;
            if(seenBack.containsKey(c)){
                distance = seenBack.get(c) - i;
            }
            seenBack.put(c,i);
            dictBack.put(i, distance);
        }
        // Now get closest element
        for(int i = 0; i<s.length();i++){
            // distance = distance between i and the closest element
            int distance = dictFront.get(i);
            if(dictFront.get(i)==-1 || (dictBack.get(i)!=-1 && dictFront.get(i)>dictBack.get(i))){
                distance = dictBack.get(i);
            }
            if (distance == dictFront.get(i)) {
                result.add(-1 * Math.abs(distance));
            }
            else {
                result.add(Math.abs(distance));
            }
        }
        return result;
    }


    public static List<Integer> closest(String s, List<Integer> queries) {
        List<Integer> ans = new ArrayList<Integer>();
        HashMap<Character, Integer> freq = new HashMap<>();
        for (int i=0; i<s.length(); i++) {
            if (freq.containsKey(s.charAt(i))) {
                freq.put(s.charAt(i), freq.get(s.charAt(i)) + 1);
            }
            else {
                freq.put(s.charAt(i), 1);
            }
        }
        List<Integer> result = preprocess(s);
        for (int i=0; i<queries.size(); i++) {
            if (freq.get(s.charAt(queries.get(i))) == 1) {
                ans.add(-1);
            }
            else {
                ans.add(queries.get(i) + result.get(queries.get(i)));
            }
        }
        return ans;
    }
}