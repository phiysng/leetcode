#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    string seller;
    string need;
    cin >> seller >> need;
    unordered_map<char, int> seller_map;
    for (char i : seller) {
        if (seller_map.find(i) == seller_map.end()) {
            seller_map[i] = 1;
        } else {
            seller_map[i]++;
        }
    }
    unordered_map<char, int> need_map;
    for (char i : need) {
        if (need_map.find(i) == need_map.end()) {
            need_map[i] = 1;
        } else {
            need_map[i]++;
        }
    }
    bool enough = true;
    int lack = 0;
    for (pair<char, int> i : need_map) {
        if (seller_map.find(i.first) == seller_map.end() || seller_map[i.first] < i.second) {
            enough = false;
            if (seller_map.find(i.first) != seller_map.end())
                lack += i.second - seller_map[i.first];
            else
                lack += i.second;
        }
    }
    if (enough)
        printf("Yes %d\n", seller.size() - need.size());
    else
        printf("No %d\n", lack);
}