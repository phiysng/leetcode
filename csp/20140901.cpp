#include <algorithm>
#include <cstring>
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
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        v[i] = t;
    }

    sort(begin(v), end(v));

    int res = 0;

    for (int i = 1; i < v.size(); ++i) {
        if (v[i] - v[i - 1] == 1) {
            ++res;
        }
    }
    cout << res << endl;

    return 0;
}
