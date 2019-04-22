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

int main(int argc, char *argv[])
{
    int c;
    cin >> c;
    unordered_set<int> set;
    for (int i = 1; i < c + 1; ++i) {
        set.insert(i / 2 + i / 3 + i / 5);
    }
    cout << set.size();

    return 0;
}