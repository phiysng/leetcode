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
    int num[10] = { 0 };
    for (int i = 0; i < 10; ++i) {
        scanf("%d", num + i);
    }
    if (num[0]) {
        for (int i = 1; i < 10; ++i) {
            if (num[i] != 0) {
                --num[i];
                cout << i;
                break;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < num[i]; ++j) {
            printf("%d" i);
        }
    }
    printf("\n");
    return 0;
}
