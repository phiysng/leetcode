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

int main(int argc, char* argv[])
{
    // 1 2 3 4 5 6 7 8
    // 3 5 8 6 2 1 4 7
    // 2 3 5 2 3 5 3 1
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        res.emplace_back(abs(m - (i + 1)));
    }
    vector<int> s(n);
    for (int i : res) {
        s[i]++;
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] > 1) {
            printf("%d %d\n", i, s[i]);
        }
    }
    return 0;
}
