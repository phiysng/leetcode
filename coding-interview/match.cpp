// 19 正则表达式匹配

// .匹配一个字符
// a*匹配0-n个a

bool match(char* str, char* pattern)
{
    if (!str || !pattern)
        return false;

    return matchCore(str, pattern);
}

bool matchCore(char* str, char* pattern)
{
    // 理想的结束状态
    if (*str == '\0' && *pattern == '\0')
        return true;

    // pattern不能全部匹配所有的字符
    if (*str != '\0' && *pattern == '\0')
        return false;

    //当下一个字符是*的时候
    if (*(pattern + 1) == '*') {
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str + 1, pattern + 2) //匹配一个
                || matchCore(str + 1, pattern) //*匹配多个字符
                || matchCore(str, pattern + 2); //匹配空
        else {
            //因为 a 与 b*的关系 只能忽略这个表达式继续求解是否匹配
            return matchCore(str, pattern + 2);
        }
    }
    //处理字符相等的情况
    if (*str == *pattern || *pattern == '.' && *str != '\0') {
        return matchCore(str + 1, pattern + 1);
    }
    return false;
}
