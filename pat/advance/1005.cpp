//PAT 甲级 1005 
//v1
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
    int64_t a;
    cin >> a;
    int64_t sum = 0;
    while (a) {
        sum += a % 10;
        a /= 10;
    }
    vector<int64_t> v;
    if (sum == 0) {
        printf("zero\n");
        return 0;
    }

    while (sum) {
        v.push_back(sum % 10);
        sum /= 10;
    }
    reverse(v.begin(), v.end());

    unordered_map<int64_t, string> map;
    map[0] = "zero";
    map[1] = "one";
    map[2] = "two";
    map[3] = "three";
    map[4] = "four";
    map[5] = "five";
    map[6] = "six";
    map[7] = "seven";
    map[8] = "eight";
    map[9] = "nine";

    for (int i = 0; i < v.size() - 1; ++i) {
        cout << map[v[i]] << " ";
    }
    cout << map[v.back()] << endl;

    return 0;
}

/////////////////////////////////////////
//v2
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

    string string1;
    cin >> string1;
    int64_t sum = 0;

    for (char c :string1) {
        sum += c - '0';
    }
    vector<int64_t> v;

    if (sum == 0) {
        printf("zero\n");
        return 0;
    }

    while (sum) {
        v.push_back(sum % 10);
        sum /= 10;
    }
    reverse(v.begin(), v.end());

    unordered_map<int64_t, string> map;
    map[0] = "zero";
    map[1] = "one";
    map[2] = "two";
    map[3] = "three";
    map[4] = "four";
    map[5] = "five";
    map[6] = "six";
    map[7] = "seven";
    map[8] = "eight";
    map[9] = "nine";

    for (int i = 0; i < v.size() - 1; ++i) {
        cout << map[v[i]] << " ";
    }
    cout << map[v.back()] << endl;

    return 0;
}