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
    int n;
    cin >> n;
    unordered_map<int, pair<string, int>> map;
    for (int i = 0; i < n; ++i) {
        string id;
        int pre, real;
        cin >> id >> pre >> real;
        map[pre] = make_pair(id, real);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        cout << map[t].first << " " << map[t].second << endl;
    }
}