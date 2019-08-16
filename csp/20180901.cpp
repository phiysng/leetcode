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
    int n;
    cin >> n;

    vector<int> arr;

    for (size_t i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    vector<int> next(n);
    next[0] = (arr[0] + arr[1]) / 2;
    next[n - 1] = (arr[n - 1] + arr[n - 2]) / 2;
    for (int i = 1; i < n - 1; i++) {
        next[i] = (arr[i - 1] + arr[i] + arr[i + 1]) / 3;
    }

    for_each(begin(next), end(next) - 1, [](int i) { cout << i << " "; });

    cout << next.back() << endl;

    return 0;
}
