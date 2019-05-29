#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
总吨数与总价格是正数 ， 而需求量是正整数，题目有误导性
-_-当然也可以说自己做题太粗心
*/

using namespace std;
struct item {
    double tons;
    double prices;
    double unit_price;
    item(double _tons = 0, double _prices = 0, double _unit_price = 0)
        : tons(_tons)
        , prices(_prices)
        , unit_price(_unit_price)
    {
    }
};

int main(int argc, char* argv[])
{
    int n, demand;
    cin >> n >> demand;

    vector<item> res(n);
    for (size_t i = 0; i < n; ++i)
        scanf("%lf", &res[i].tons);
    for (size_t i = 0; i < n; ++i)
        scanf("%lf", &res[i].prices);
    for (size_t i = 0; i < n; ++i)
        res[i].unit_price = res[i].prices / res[i].tons;

    sort(res.begin(), res.end(), [](const item& a, const item& b) -> bool { return a.unit_price > b.unit_price; });

    double all = 0;

    for (int i = 0; i < res.size(); ++i) {
        if (demand - res[i].tons >= 0) {
            demand -= res[i].tons;
            all += res[i].prices;
        } else {
            all += demand * res[i].unit_price;
            break;
        }
    }
    printf("%.2f\n", all);
    return 0;
}