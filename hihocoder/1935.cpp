#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int64_t n, c;
    while(cin >> n >> c){
    int64_t t;
    vector<int> dis, need;
 

    for (int i = 0; i < n; ++i) {
        cin >> t;
        dis.push_back(t);
    }
    for (int i = 0; i < n; ++i) {
        cin >> t;
        need.push_back(t);
    }
    if (n == 1) {
        cout << 2 * dis[0] << endl;
        continue;
    }
    int64_t capacity = c;
    int64_t res = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (i == 0)
            res += dis[0];
        else
        {
            res += dis[i] - dis[i - 1];
        }
        capacity -= need[i];
        if (capacity >= need[i+1])
        {
            
        } else 
        {
            capacity = c;
            res += 2 * dis[i];
        }
    }
    res += dis[n - 1] - dis[n - 2];
    res += dis[n - 1];
    cout << res << endl;
        
    }
    return 0;
}
