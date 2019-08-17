#include <algorithm>                                                                                                                                                                                               #include <cstring>
#include <iostream>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int max_diff = 0;

    int prev;
    int curr;
    cin >> prev;

    for (int i = 0; i < n - 1; ++i) {
        cin >> curr;
        max_diff = max(max_diff, abs(curr - prev));
        prev = curr;
    }

    cout << max_diff << endl;

    return 0;
}
