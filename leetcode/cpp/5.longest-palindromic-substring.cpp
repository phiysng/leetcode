class Solution {
public:
    string longestPalindrome(string s)
    {
        if (s.length() == 0)
            return "";
        int start = 0, end = 0;

        for (int i = 0; i < s.length(); i++) {
            //从中心向两边扩展所能获得的最长长度
            int len1 = expandaAroundCenter(s, i, i);
            int len2 = expandaAroundCenter(s, i, i + 1);

            int len = max(len1, len2); // 两种方案下最长的那种
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    ///
    /// \brief expandaAroundCenter  Time O(n)
    /// \param s
    /// \param l
    /// \param r
    /// \return
    ///
    int expandaAroundCenter(string& s, int l, int r)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        return r - l - 1;
    }
};