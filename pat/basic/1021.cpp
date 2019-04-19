#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt[10] = {0};
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i] - '0']++;
    }
    for (int j = 0; j < 10; ++j) {
        if (cnt[j])
            printf("%d:%d\n", j, cnt[j]);
    }
    return 0;
}