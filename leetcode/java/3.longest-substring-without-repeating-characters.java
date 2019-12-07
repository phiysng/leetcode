import java.util.HashMap;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int sub_start = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i)) && map.get(s.charAt(i)) >= sub_start) {
                sub_start = map.get(s.charAt(i)) + 1;
            }
            map.put(s.charAt(i), i);
            res = Math.max(res, i - sub_start + 1);
        }

        return res;

    }
}
