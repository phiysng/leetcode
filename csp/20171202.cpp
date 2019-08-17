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

    vector<int> v(n);
    iota(begin(v), end(v), 0);

    queue<int> q;
    for_each(begin(v), end(v), [&q](int i) { q.push(i); });

    int i = 0;

    while (q.size() > 1) {
        ++i;
        int t = q.front();
        q.pop();
        if (i % k == 0 || i % 10 == k) {
            continue;
        } else {
            q.push(t);
        }
    }

    cout << q.front() + 1 << endl;

    return 0;
}
