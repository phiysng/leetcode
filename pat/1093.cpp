#include<cstdio>
#include<cmath>
#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>


using namespace std;

int main(int argc, char *argv[])
{
    string s, v;
    getline(cin, s);
    getline(cin, v);
    s = s + v;
    unordered_set<char> set;
    for (char c : s) {
        if (set.find(c) == set.end()) {
            printf("%c", c);
            set.insert(c);
        }
    }
    printf("\n");
    return 0;
}