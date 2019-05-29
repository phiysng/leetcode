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
    int n;
    cin >> n;
    double max_mode = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        max_mode = max(max_mode, sqrt(a * a + b * b));
    }
    printf("%.2f", max_mode);
    return 0;
}