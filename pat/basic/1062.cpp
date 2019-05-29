#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int a, b, c, d, e;
    scanf("%d/%d %d/%d %d", &a, &b, &c, &d, &e);
    if (a * d > b * c) {
        swap(a, c);
        swap(b, d);
    }
    double beg = 1.0 * a / b;
    double end = 1.0 * c / d;
    int i = 1;
    while (1.0 * i / e <= beg)
        ++i;
    vector<int> upper;
    while (1.0 * i / e < end) {
        if (gcd(i, e) == 1)
            upper.push_back(i);
        ++i;
    }
    for (int i = 0; i < upper.size() - 1; ++i) {
        printf("%d/%d ", upper[i], e);
    }
    printf("%d/%d\n", upper[upper.size() - 1], e);
    return 0;
}
