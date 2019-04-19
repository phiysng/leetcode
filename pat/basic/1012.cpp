#include<cstdio>
#include<cmath>
#include<climits>
#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int nu;
    cin >> nu;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = INT_MIN;
    vector<int> a2_vec;
    int num = 0;//a4的数量 用于计算平均数
    for (int i = 0; i < nu; ++i) {
        int x;
        cin >> x;
        if (x % 10 == 0) a1 += x;
        if (x % 5 == 1) a2_vec.push_back(x);
        if (x % 5 == 2) a3++;
        if (x % 5 == 3) {
            a4 += x;
            ++num;
        }
        if (x % 5 == 4) a5 = max(x, a5);

    }
    //交替计算
    for (int i = 1; i < a2_vec.size(); i += 2) {
        a2_vec[i] = -a2_vec[i];
    }
    for (int i : a2_vec) a2 += i;

    double res_a4 =  1.0 * a4 / num;

    if (a1 != 0)printf("%d ", a1) ;
    else  printf("N ");
    if (a2_vec.size() != 0) printf("%d ", a2);
    else  printf("N ");
    if (a3 != 0)printf("%d ", a3);
    else  printf("N ");
    if (a4 != 0)printf("%.1f ", res_a4);
    else  printf("N ");
    if (a5 != INT_MIN)printf("%d\n", a5);
    else  printf("N\n");
    return 0;
}