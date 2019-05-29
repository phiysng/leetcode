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

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    getchar(); //读掉\n
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        size_t pos = s.find('T');
        char ch = s[pos - 2];
        if (ch == 'A')
            printf("1");
        if (ch == 'B')
            printf("2");
        if (ch == 'C')
            printf("3");
        if (ch == 'D')
            printf("4");
    }
    printf("\n");

    return 0;
}
