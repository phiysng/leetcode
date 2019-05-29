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
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        if (s.size() < 6) {
            cout << "Your password is tai duan le." << endl;
            continue;
        }

        bool has_illegal = false;
        for (char c : s) {
            if (!isalpha((c)) && c != '.' && !isdigit(c)) {
                cout << "Your password is tai luan le." << endl;
                has_illegal = true;
                break;
            }
        }
        if (has_illegal)
            continue;
        bool has_digit = false, has_char = false;
        for (char c : s) {
            if (isdigit(c))
                has_digit = true;
            if (isalpha(c))
                has_char = true;
        }
        if (!has_digit) {
            cout << "Your password needs shu zi." << endl;
            continue;
        }
        if (!has_char) {
            cout << "Your password needs zi mu." << endl;
            continue;
        }
        cout << "Your password is wan mei." << endl;
    }

    return 0;
}