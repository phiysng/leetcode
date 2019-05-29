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
    int n, shift;
    cin >> n >> shift;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    vector<int> cp(a.begin(), a.end());
    shift %= n;
    for (int i = 0; i < n; ++i) {
        a[(i + shift) % n] = cp[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
    return 0;
}