///面试题5 替换空格

class Solution {
public:
    void replaceSpace(char* str, int length)
    {
        if (str == NULL || length <= 0)
            return;
        int len = strlen(str);
        char* p = str;
        int cnt = 0;
        while (*p != '\0') {
            if (*p == ' ') {
                ++cnt;
            }
            ++p;
        }
        int rlen = len + 2 * cnt;
        if (rlen > length)
            return;
        int origin = len, curr = rlen; //从尾向头复制  包含最后的 '\0'
        while (origin >= 0 && origin < curr) {
            if (str[origin] == ' ') {
                str[curr--] = '0';
                str[curr--] = '2';
                str[curr--] = '%';
            } else {
                str[curr--] = str[origin];
            }
            --origin;
        }
    }
};

/// 合并排序的数组A1 A2 保证A1后面有足够的空余空间
