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
void prime_func(vector<int>& res)
{
    for (int i = 2; i < res.size(); ++i) {
        if (res[i]) {
            for (int j = 2; i * j < res.size(); ++j) {
                res[i * j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> prime(n + 1, 1);
    prime_func(prime);
    int j = 3;

    int cnt = 0;
    for (int k = 4; k < n + 1; ++k) {
        if (prime[k]) {
            if (k - j == 2)
                ++cnt;
            j = k;
        }
    }
    cout << cnt << endl;
    return 0;
}