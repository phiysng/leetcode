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
    int a, b;
    cin >> a >> b;
    vector<int> arr(a);
    for (size_t i = 0; i < b; ++i) {
        for (int j = 0; j < a; ++j) {
            int t;
            cin >> t;
            arr[j] += t;
        }
    }
    int max_sales = *max_element(arr.begin(), arr.end());
    printf("%d\n", max_sales);
    vector<int> cites;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == max_sales) cites.emplace_back(i + 1);
    }
    for (size_t i = 0; i < cites.size() - 1; ++i) {
        printf("%d ", cites[i]);
    }
    printf("%d", cites.back());
    return 0;
}