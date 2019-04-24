#include<cstdio>
#include<cmath>
#include<climits>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<functional>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int master_id = -1, amateur_id = -1;
    int master = 200000, amateur = -1;
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        int x, y;
        cin >> x >> y;
        int dis = x * x + y * y;
        if (dis < master) {
            master = dis;
            master_id = id;
        }
        if (dis > amateur) {
            amateur_id = id;
            amateur = dis;
        
        }
    }
    printf("%04d %04d\n", master_id, amateur_id);
    return 0;
}
