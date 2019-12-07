class Solution {
    public String countAndSay(int n) {
        StringBuilder sb = new StringBuilder("1");

        for (int k = 0; k < n - 1; k++) {
            char ch = sb.charAt(0);
            int cnt = 1;
            StringBuilder iter = new StringBuilder();
            int len = sb.toString().length();
            for (int i = 1; i < len; i++) {

                if (ch == sb.charAt(i)) {
                    ++cnt;
                } else {
                    iter.append(cnt);
                    iter.append(ch);
                    ch = sb.charAt(i);
                    cnt = 1;
                }

            }
            iter.append(cnt);
            iter.append(ch);
            sb = iter;
        }
        
        return sb.toString();
    }
}