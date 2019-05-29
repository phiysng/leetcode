#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
/*
这个题审题不清 结果素数筛选法上少算了数字，
以为是在1-10000范围内的素数，实际上是第1-10000个素数，所以被卡
10000 10000
这种用例
*/

using namespace std;

void prime_func(vector<int>& res)
{
    for (int i = 2; i < res.size(); ++i) {
        if (res[i]) {
            for (int j = 2; i * j < res.size(); ++j) {
                res[i * j] = 0;
            }
        }
    }
}
int main(int argc, char* argv[])
{
    vector<int> is_prime(1000000, 1);
    is_prime[0] = 0;
    prime_func(is_prime);
    int m, n;
    cin >> m >> n;
    vector<int> res;
    int cnt = 0;
    int t = 0;
    for (int i = 2; i < is_prime.size(); ++i) {

        if (is_prime[i]) {
            ++cnt;
            if (m > cnt)
                continue;
            if (n < cnt)
                break;

            res.push_back(i);
        }
    }
    for (int i = 0; i < res.size(); ++i) {

        ++t;
        if (t % 10 != 1) {
            printf(" ");
        }
        printf("%d", res[i]);
        if (t % 10 == 0)
            printf("\n");
    }
    return 0;
}