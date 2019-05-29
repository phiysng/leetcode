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

int main()
{
    int a, b;
    cin >> a >> b;
    int64_t res = a * b;
    while (res % 10 == 0)
        res /= 10;
    while (res) {
        printf("%d", res % 10);
        res /= 10;
    }
    cout << endl;
    return 0;
}
