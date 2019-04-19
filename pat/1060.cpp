#include<cstdio>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<functional>

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