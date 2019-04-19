#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <list>
#include <unordered_map>
//#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[256] = {0};

    string s;
    getline(cin, s);
//    cout << s << endl;
    for (auto x : s) {
        if (isalpha(x))
            arr[tolower(x)]++;
    }
    int idx;
    int num = -1;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (arr[i] > num) {
            num = arr[i];
            idx = i;
        }

    }
    printf("%c %d", idx, num);
    return 0;
}