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
 
        unordered_set<int> set;
        for (int i = 0; i < t ; ++i) {
            int m;
            cin >> m;
            set.insert(m);
        }
        vector<int> res(set.begin(), set.end());
        sort(res.begin(), res.end());
        for (int i : res) {
            cout << i << endl;
        }
    }
    return 0;
}