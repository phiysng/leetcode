#include<cstdio>
#include<cmath>
#include<climits>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        vector<int> res;
        int teacher = 0;
        cin >> teacher;
        for (int j = 0; j < n - 1; ++j) {
            int t;
            cin >> t;
            if (t >= 0 && t <= m) res.push_back(t);
        }
        sort(res.begin(), res.end());
        double sum = 0;
        for (auto it = res.begin() + 1; it != res.end() - 1; ++it) {
            sum += *it;
        }
        sum /= res.size() - 2;
        double_t result = (sum + teacher) / 2;
        int ave = (int) result;
        if (result - (int) result >= 0.5) ++ave;
        printf("%d\n", ave);
    }
    return 0;
}