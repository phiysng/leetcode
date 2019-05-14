#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        vector<int> res;
        int a, b;
        a = b = 0;
        unordered_set<int> set;
        for (int k = 0; k < m; ++k)
        {
            int t;
            cin >> t;
            if (t - 3 <= 0)
                ++b;
            res.push_back(t);
            set.insert(t);
        }
        int idx = 0;
        bool con = true;
        for (int var = 0; var < res.size(); ++var)
        {
            if (con)
            {
                con = false;
                for (int k = 0; k < res.size(); ++k)
                {
                    res[k]--;
                    if (res[k] == 0)
                    {
                        ++a;
                        con = true;
                    }
                }
            }
        }
        //        for (int j = 1; j < res.size(); ++j) {
        //            if (set.find(j) == set.end())
        //                break;
        //            else {
        //                idx = j;
        //            }
        //        }

        //        for (int i : res) {
        //            if (i - idx <= 0) {
        //                ++a;
        //            }
        //        }
        if (a > b)
        {
            printf("Defile\n");
        }
        else
        {
            if (a < b)
            {
                printf("Hellfire\n");
            }
            else
            {
                printf("Tie\n");
            }
        }
    }
    return 0;
}