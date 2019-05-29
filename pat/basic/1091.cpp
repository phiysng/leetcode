#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    int nu;
    cin >> nu;
    for (int i = 0; i < nu; ++i) {
        int n;
        cin >> n;
        int n_pow = n * n;
        string str_n = to_string(n);
        string str_n_pow = to_string(n_pow);
        //int mod_v = n * 10 ;
        bool f = true;
        for (int j = 1; j < 10; ++j) {
            string t = to_string(n_pow * j);
            // 12121 121
            if (t.substr(t.size() - str_n.size()) == str_n) {
                {
                    cout << j << " " << t << endl;
                    f = false;
                    break;
                }
            }
        }
        if (f) {
            printf("No\n");
        }
    }
    return 0;
}