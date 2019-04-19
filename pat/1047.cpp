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
    int team, id, score;
    int arr[10000 + 1] = {};
    for (int i = 0; i < n; ++i) {
        scanf("%d-%d %d", &team, &id, &score);
        arr[team] += score;
    }
    int idx = 0;
    for (int i = 1; i < 10000 + 1; ++i) {
        if (arr[i] > arr[idx]) idx = i;
    }
    printf("%d %d\n", idx, arr[idx]);
    return 0;
}