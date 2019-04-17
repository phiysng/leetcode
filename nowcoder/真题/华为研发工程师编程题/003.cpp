#include<cstdio>
#include<cmath>
#include<climits>
#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
 
using namespace std;
int main()
{
    string s;
    unordered_map<char, int> map;
    map['a'] = 10;
    map['b'] = 11;
    map['c'] = 12;
    map['d'] = 13;
    map['e'] = 14;
    map['f'] = 15;
    while (cin >> s) {
        int res = 0;
        string r = s.substr(2);
        for (char c : r) {
            res *= 16;
            c = tolower(c);
            if (c >= '0' && c <= '9')
                res += c - '0';
            else res += map[c];
        }
        cout << res << endl;
    }
    return 0;
}