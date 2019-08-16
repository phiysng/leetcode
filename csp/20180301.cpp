/**
 * 跳一跳
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
    vector<int> v;
    int c;
    while (cin >> c) {
        if (c == 0)
            break;
        v.push_back(c);
    }
    
    int cnt;
    int res = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (i == 0 && v[i] == 2 || v[i] == 2 && v[i - 1] == 1) {
            res += 2;
            cnt = 1;
        } else if (v[i] == 1) {
            res += 1;
            cnt = 0;
        } else {
            ++cnt;
            res += 2 * cnt;
        }
    }
    cout << res << endl;

    return 0;
}
