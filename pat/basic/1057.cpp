#include<cstdio>
#include<cmath>
#include <iostream>
#include<vector>
#include<stack>
#include<unordered_map>


using namespace std;

int main(int argc, char *argv[])
{
    string s;
    getline(cin, s);
    int sum = 0;
    for (char c : s) {
        if (isalpha(c)) {
            c = tolower(c);
            sum += 1 + c - 'a';
        }
    }
    int cnt = 0;
    int one = 0;
    while (sum) {
        ++cnt;
        if (sum & 0x1) {
            ++one;
        }
        sum >>= 1;
    }
    printf("%d %d\n", cnt - one, one);
    return 0;
}