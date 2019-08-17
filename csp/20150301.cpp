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

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    vector<vector<int>> res;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int t;
            cin >> t;
            matrix[i][j] = t;
        }
    }

    for (int i = m - 1; i >= 0; --i) {
        vector<int> t;
        for (int j = 0; j < n; ++j) {
            t.push_back(matrix[j][i]);
        }
        res.push_back((t));
    }
    for_each(begin(res), end(res), [](vector<int> &v) {
        for_each(begin(v), end(v) - 1, [](int &i) { cout << i << " "; });
        cout << v.back() << endl;
    });

    return 0;
}
