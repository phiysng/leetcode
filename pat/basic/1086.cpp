#include<cstdio>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
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
    int64_t res = a * b;
    while (res % 10 == 0) res /= 10;
    while (res) {
        printf("%d", res % 10);
        res /= 10;
    }
    cout << endl;
    return 0;
}
