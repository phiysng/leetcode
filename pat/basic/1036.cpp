#include <algorithm>
#include <climits>
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
    char c;
    cin >> nu >> c;
    int col = nu, row = (int)(0.5 * nu);
    if (0.5 * nu - row >= 0.5)
        ++row;
    //第一行
    for (int i = 0; i < col; ++i)
        cout << c;
    cout << endl;
    //中间
    int mid = row - 2;
    for (int i = 0; i < mid; ++i) {
        cout << c;
        for (int j = 0; j < col - 2; ++j) {
            cout << ' ';
        }
        cout << c << endl;
        ;
    }
    //最后一行
    for (int i = 0; i < col; ++i)
        cout << c;
    cout << endl;
    return 0;
}
