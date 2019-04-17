#include<cstdio>
#include<cmath>
#include<climits>
#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
 
using namespace std;
 
int main()
{
    int t;
 
    while (cin >> t) {
        if (t == 0)break;
        int res = 0;
 
        while (t >= 2) {
            if (t == 2) {
                ++res;
                break;
            }
 
            res += t / 3;
            t = t % 3 + t / 3;
 
        }
        cout << res << endl;
    }
}

