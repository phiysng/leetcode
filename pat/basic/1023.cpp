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
    int num[10] = {0};
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
