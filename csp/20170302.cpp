#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

/// rotate函数 见
/// ref: https://zh.cppreference.com/w/cpp/algorithm/rotate

using namespace std;

int main(int argc, char *argv[])
{
    int n, m;
    cin >> n >> m;
    std::vector<int> v(n);

    iota(v.begin(), v.end(), 1);

    for (int i = 0; i < m; ++i) {
        int t , step;
        cin >> t >> step;
        auto it = find(v.begin(), v.end(),t);
        if(step > 0)//向右移动
        {
            rotate(it, it + 1, it + step + 1);
        }
        else // 向左移动
        {
            rotate(it + step, it, it + 1);
        }
    }
    for_each(v.begin(), v.end() - 1, [](int &i) { cout << i << " "; });
    cout << v.back() << endl;
    return 0;
}
