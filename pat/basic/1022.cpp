#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    int64_t a, b, x;
    cin >> a >> b >> x;
    int64_t sum = a + b;
    if (sum == 0) {
        printf("0\n");
        return 0;
    }
    stack<int64_t> s;
    while (sum) {
        s.push(sum % x);
        sum /= x;
    }
    while (!s.empty()) {
        printf("%d", s.top());
        s.pop();
    }
    printf("\n");
    return 0;
}