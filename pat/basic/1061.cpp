#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> points(m), ans(m);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        points[i] = x;
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        ans[i] = x;
    }
    for (int i = 0; i < n; ++i) {
        int res = 0;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if (x == ans[j])
                res += points[j];
        }
        cout << res << endl;
    }
    return 0;
}