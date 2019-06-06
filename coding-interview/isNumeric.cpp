// 20 表示数值的字符串

// 细节题

/// 数字的格式 A[.[B]][e|EC] 或者 .B[e|EC]

bool scanUnsignedInteger(const char** str)
{
    const char* before = *str;

    while (**str != '\0' && **str >= '0' && **str <= '9') {
        ++(*str);
    }

    // 存在整数部分
    return *str > before;
}

bool scanInteger(const char** str)
{
    if (**str == '+' || **str == '-')
        ++(*str);
    return scanUnsignedInteger(str);
}

bool isNumeric(const char* str)
{
    if (!str)
        return false;
    bool numeric = scanInteger(&str);

    //存在小数部分
    if (*str == '.') {
        ++str;

        // 1.  .123 == 0.123
        // 2.  223. == 223.0
        // 3. 223.456
        // ⭐⭐⭐  注意不能将 numeric放在前面，这样 numeric == true 时表达式会直接短路
        // 不会操作str了
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    //可选的科学计数法部分
    if (*str == 'e' || *str == 'E') {
        ++str;

        // 1. E的前面没有数字非法 .e1 E1
        // 2. E的后面没有整数时非法 12E 12e+5.4

        // 前面没有数字 直接短路 前面有数字，便向后扫描，看是否能够全部读成整数
        numeric = numeric && scanInteger(&str);
    }

    return numeric && *str == '\0';
}
