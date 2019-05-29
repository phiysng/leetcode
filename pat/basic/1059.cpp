#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void prime_func(vector<int>& res)
{
    for (int i = 2; i < res.size(); ++i) {
        if (res[i]) {
            for (int j = 2; i * j < res.size(); ++j) {
                res[i * j] = 0;
            }
        }
    }
}
int main(int argc, char* argv[])
{
    vector<int> is_prime(10000, 1);
    is_prime[0] = 0;
    prime_func(is_prime);

    int n;
    cin >> n;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        map[id] = i + 1;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        if (map.find(id) != map.end()) {
            if (map[id] > 0) {

                if (map[id] == 1) {
                    printf("%04d: Mystery Award\n", id);
                    map[id] = 0;

                } else {
                    if (is_prime[map[id]]) {
                        printf("%04d: Minion\n", id);
                        map[id] = 0;
                    } else {
                        printf("%04d: Chocolate\n", id);
                        map[id] = 0;
                    }
                }
            } else {
                printf("%04d: Checked\n", id);
            }
        } else {
            printf("%04d: Are you kidding?\n", id);
        }
    }
    return 0;
}