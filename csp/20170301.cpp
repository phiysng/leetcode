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
    int n, k;
    cin >> n >> k;

    int res = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        curr += t;
        if (curr >= k) {
            curr = 0;
            ++res;
        }
    }
    if (curr > 0)
        ++res;
    cout << res << endl;

    return 0;
}
