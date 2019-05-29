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
    int n, m, a, b;
    cin >> n >> a >> m >> b;
    int ana = 0, anb = 0;
    while (n) {
        if (n % 10 == a) {
            ana *= 10;
            ana += a;
        }
        n /= 10;
    }
    while (m) {
        if (m % 10 == b) {
            anb *= 10;
            anb += b;
        }
        m /= 10;
    }
    printf("%d\n", ana + anb);
}