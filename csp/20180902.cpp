#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> pos(10000001);

    //思路: 暴力穷举交集

    for (int var = 0; var < 2; ++var) {
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            for_each(begin(pos) + a, begin(pos) + b, [](int &a) { a += 1; });
        }
    }

    int res = 0;

    for_each(begin(pos), end(pos), [&res](int &i) {
        if (i == 2) {
            res++;
        }
    });

    cout << res << endl;

    return 0;
}
