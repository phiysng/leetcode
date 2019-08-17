#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;
int main(int argc, char *argv[])
{
    string s;
    cin >> s;
    int flag;
    int n;
    cin >> flag >> n;
    if (flag == 0) {
        for_each(begin(s), end(s), [](char &c) { c = toupper(c); });
    }
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        string _str = str;
        if (flag == 0) {
            for_each(begin(str), end(str), [](char &c) { c = toupper(c); });
        }
        if (str.find(s) != string::npos) {
            cout << _str << endl;
        }
    }

    return 0;
}
