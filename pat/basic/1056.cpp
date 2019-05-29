#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (map.find(t) == map.end()) {
            map[t] = 1;
        } else {
            map[t]++;
        }
    }
    //sort(a.begin(), a.end());
    int sum = 0;

    a.reserve(map.size());
    for (pair<int, int> i : map) {
        a.push_back(i.first);
        if (i.second >= 2) {
            sum += i.first * 10 + i.first;
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            sum += a[i] * 10 + a[j];
            sum += a[i] + a[j] * 10;
        }
    }
    printf("%d\n", sum);
    return 0;
}