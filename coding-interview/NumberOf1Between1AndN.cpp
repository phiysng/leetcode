// 43 1~n整数中1出现的次数

/// O(nlogn)
int NumberOf1(unsigned n)
{
    int num = 0;
    while (n) {
        n /= 10;
    }

    return num;
}

int NumberOf1Between1AndN(unsigned n)
{
    int num = 0;
    for (size_t i = 1; i < n + 1; i++) {
        num += NumberOf1(i);
    }

    return num;
}

/// TODO: 更好的方法

