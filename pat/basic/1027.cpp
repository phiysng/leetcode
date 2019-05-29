#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    int n;
    char c;
    cin >> n >> c;
    int level = (int)sqrt((n + 1) / 2);
    int left = n - ((level * level) * 2 - 1);
    for (int i = level; i > 0; --i) {
        for (int j = 0; j < level - i; ++j) {
            cout << " ";
        }
        for (int j = i * 2 - 1; j > 0; --j) {
            cout << c;
        }
        cout << endl;
    }
    for (int i = 2; i <= level; ++i) {
        for (int j = 0; j < level - i; ++j) {
            cout << " ";
        }
        for (int j = 0; j < i * 2 - 1; ++j) {
            cout << c;
        }
        cout << endl;
    }
    cout << left << endl;
    return 0;
}