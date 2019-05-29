#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    int nu;
    cin >> nu;
    int scores[101] = { 0 };
    for (int i = 0; i < nu; ++i) {
        int t = 0;
        cin >> t;
        scores[t]++;
    }
    cin >> nu;
    int t;
    cin >> t;
    printf("%d", scores[t]);
    for (int i = 1; i < nu; ++i) {
        int t_;
        cin >> t_;
        printf(" %d", scores[t_]);
    }
    return 0;
}