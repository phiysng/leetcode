#include<cstdio>
#include<cmath>
#include <iostream>
#include<vector>
#include<stack>
#include<unordered_map>


using namespace std;

int main(int argc, char *argv[])
{
    int n;
    double rate;
    int limit;
    cin >> n >> rate >> limit;
    int may = 0, do_empty = 0;
    for (int i = 0; i < n; ++i) {
        int days;
        cin >> days;
        int low = 0;
        for (int j = 0; j < days; ++j) {
            double m;
            cin >> m;
            if (m < rate ) {
                ++low;
            }
        }
        if (low > days / 2) {
            if (days > limit) {
                do_empty++;
            } else
                may++;
        }
    }
    printf("%.1f%% %.1f%%\n", 1.0 * may / n * 100, 1.0 * do_empty / n * 100);
    return 0;
}