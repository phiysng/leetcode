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
    int n;
    cin >> n;
    // n不足四位要补0 同时特殊处理6174 这个数字需要至少执行一次
    // 中间的输出也要注意补足四位 特别是 s2
    do {
        string s = to_string(n);
        s.insert(0, 4 - s.size(), '0');

        sort(s.begin(), s.end(), [](char a, char b)
        { return a > b; });

        string s1 = s;
        sort(s1.begin(), s1.end());

        n = stoi(s) - stoi(s1);

        string s2 = to_string(n);
        s2.insert(0, 4 - s2.size(), '0');

        cout << s << " - " << s1 << " = " << s2 << endl;
    }
    while (n != 6174 && n != 0);
    return 0;
}
