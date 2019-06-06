// 64 求 1+2+...+n

// 不允许使用可以进行条件判断的关键字及条件判断语句

// 构造函数
class Sum_v1 {
public:
    Sum_v1()
    {
        ++N;
        Sum += N;
    }
    static void Reset()
    {
        N = 0;
        Sum = 0;
    }
    static unsigned int GetSum() { return Sum; }

private:
    static unsigned int N;
    static unsigned int Sum;
};

unsigned int Sum_v1::N = 0;
unsigned int Sum_v1::Sum = 0;

unsigned int Sum_wrapper_v1(unsigned int n)
{
    Sum_v1::Reset();
    Sum_v1* a = new Sum_v1[n];

    delete[] a;
    a = nullptr;
    return Sum_v1::GetSum();
}

// 虚函数
class A;
A* Array[2];

class A {
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return n;
    }
};

class B : public {
public:
    virtual unsigned int Sum(unsigned int n)

    {
        return Array[!!n]->Sum(n - 1) + n;
    }
};

// 非0时调用B::Sum  0时调用A::Sum.
int Sum_wrapper_v2(int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int res = Array[1]->Sum(n);
}

/// 函数指针

// 定义 fun为接受 unsigned int 返回 unsigned int 的函数指针
typedef unsigned int (*fun)(unsigned int);

unsigned int Sum_Terminator(unsigned int n)
{
    return 0;
}

unsigned int Sum_wrapper_v3(unsigned int n)
{
    // 定义函数指针数组
    // 其余的与v2相似
    static fun f[2] = { Sum_Terminator, Sum_wrapper_v3 };
    return n + f[!!n](n - 1);
}

// 模板类型
// 编译时展开模板时完成计算 需要编译时常量
// n不能过大 因为模板的递归深度有限制
template <unsigned int n>
struct Sum_v4 {
    enum Value { N = Sum_v4<n - 1>::N + n };
};

template <>
struct Sum_v4<1> {
    enum Value { N = 1 };
};
