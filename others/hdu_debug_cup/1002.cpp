#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int nu;
    cin >> nu;
    for (int i = 0; i < nu; ++i)
    {
        int time[24 * 60 * 60 + 10] = {};
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < a; ++i)
        {
            int h, m, s, mount = 0;
            scanf("%d:%d:%d %d", &h, &m, &s, &mount);
            int t = h * 60 * 60 + m * 60 + s;
            time[t] += mount;
        }
        int res[24 * 60 * 60 + 10] = {};
        res[0] = time[0];
        for (int i = 1; i < 24 * 60 * 60; ++i)
        {
            res[i] = res[i - 1] + time[i];
        }
        for (int i = 0; i < b; ++i)
        {
            int h, m, s, h_, m_, s_;
            scanf("%d:%d:%d %d:%d:%d", &h, &m, &s, &h_, &m_, &s_);
            int t1 = h * 60 * 60 + m * 60 + s;
            int t2 = h_ * 60 * 60 + m_ * 60 + s_;
            /*   */
            cout << res[t2] - res[t1 - 1] << endl;
        }
    }

    return 0;
}