// 65 不用加减乘除做加法

// 加法器原理
// 异或操作做不进位加法
// & 操作与<< 1 获得进位的结果
int Add(int num1, int num2)
{
    int sum, carry;

    do {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1; // << 进位操作
        num1 = sum;
        num2 = carry;
    } while (num2 != 0);

    return num1;
}
