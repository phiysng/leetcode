#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    unordered_multimap<int, int> map;
    for (int i = 0; i < a; ++i) {
        int m, n;
        cin >> m >> n;
        map.insert(unordered_multimap<int, int>::value_type(m, n));
        map.insert(unordered_multimap<int, int>::value_type(n, m));
    }

    for (int i = 0; i < b; ++i) {
        int c;
        cin >> c;
        unordered_set<int> set;
        for (int j = 0; j < c; ++j) {
            int t;
            cin >> t;
            set.insert(t);
        }
        bool legal = true;
        for (int item : set) {
            auto pair = map.equal_range(item);

            for (; pair.first != pair.second; ++pair.first) {
                if (set.find(pair.first->second) != set.end()) {
                    legal = false;
                    printf("No\n");
                    goto label;
                }
            }
        }
    label:
        if (legal) {
            printf("Yes\n");
        }
    }
    return 0;
}