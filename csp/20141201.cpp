#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> map;

    for (int i = 0; i < n - 1; ++i) {
        int n;
        cin >> n;
        cout << ++map[n] << " ";
    }

    int t;
    cin >> t;
    cout << ++map[t] << endl;

    return 0;
}
