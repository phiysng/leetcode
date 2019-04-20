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
//using namespace vector;
int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        map[a] = b;
        map[b] = a;
    }

    int c;
    cin >> c;
    vector<int> arr(c), single;
    for (int i = 0; i < c; ++i) {
        cin >> arr[i];
    }
    unordered_set<int> may_single;//可能单身的群体，couple可能没有同时来
    for (int i : arr) {
        if (map.find(i) == map.end()) {
            single.push_back(i);
        }
        else {
            may_single.insert(i);
        }
    }
    for (int i : may_single) {
        if (may_single.find(map[i]) == may_single.end()) {
            single.push_back(i);
        }
    }
    sort(single.begin(), single.end());
    printf("%d\n", single.size());
    
    if(single.size() == 0){
        //printf("\n");
        return 0;
    }
    for (int i = 0; i < single.size() - 1; ++i) {
        printf("%05d ", single[i]);
    }
    printf("%05d\n", single.back());

    return 0;
}