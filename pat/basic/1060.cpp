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

/**
读清题 要求有K个大于K的数的K
*/

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        if (i + 1 < arr[i])
            cnt = i + 1;
        else
            break;
    }
    printf("%d\n", cnt);
    return 0;
}