// 63 股票的最大利润

// 只许买卖一次时能够获得的最大利润

int MaxDiff(const int* numbers, int len)
{
    if (numbers == nullptr || len < 2)
        return 0;

    int min_v = numbers[0]; // 当前n-1个值中的最小值
    int maxDiff = numbers[1] - min_v; // 当前的最大利润

    for (int i = 2; i < len; i++) {
        // 前 i - 1 个价格中最低的那个
        if (numbers[i - 1] < min_v)
            min_v = numbers[i - 1];

        int currentDiff = numbers[i] - min_v;
        maxDiff = currentDiff > maxDiff ? currentDiff : maxDiff;
    }

    return maxDiff;
}
