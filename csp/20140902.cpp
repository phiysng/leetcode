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

///ref https://stackoverflow.com/questions/29618367/iterate-over-vectorvector-with-for-each

int main(int argc, char *argv[])
{
    vector<vector<int>> arr(101, vector<int>(101));
    //vector<int> a(10, -1);

    int xx, xy, yx, yy;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> xx >> xy >> yx >> yy;
        for (int j = xx; j < yx; ++j) {
            for (int k = xy; k < yy; ++k) {
                arr[j][k]++;
            }
        }
    }

    int res = 0;
    for_each(begin(arr), end(arr), [&res](vector<int> &x) {
        //int t = res;
        for_each(begin(x), end(x), [&res](int &i) {
            if (i > 0) {
                ++res;
            }
        });
    });

    cout << res << endl;

    return 0;
}
