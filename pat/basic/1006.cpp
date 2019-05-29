#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
//代码有点丑，直接暴力穷举了
int main(int argc, char* argv[])
{
    int c;
    cin >> c;
    stack<int> s;
    while (c) {
        s.push(c % 10);
        c /= 10;
    }
    int hun = 0, ten = 0, one = 0;
    if (s.size() == 3) {
        hun = s.top();
        s.pop();
        ten = s.top();
        s.pop();
        one = s.top();
        s.pop();
    }
    if (s.size() == 2) {
        ten = s.top();
        s.pop();
        one = s.top();
        s.pop();
    }
    if (s.size() == 1) {
        one = s.top();
        s.pop();
    }
    for (int i = 0; i < hun; ++i) {
        printf("B");
    }
    for (int i = 0; i < ten; ++i) {
        printf("S");
    }
    for (int i = 1; i < one + 1; ++i) {
        printf("%d", i);
    }
    cout << endl;
    return 0;
}