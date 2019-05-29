// 礼物的最大价值
#include "array_util.h"
using namespace std;

/// dp
int getMaxValue_v1(vector<vector<int>> values)
{
    if (values.size() == 0)
        return 0;
    if (values[0].size() == 0)
        return 0;
    int rows = values.size();
    int cols = values[0].size();

    vector<vector<int>> max_v(rows, vector<int>(cols));

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            int left = 0, up = 0;
            if (i > 0)
                up = max_v[i - 1][j];
            if (j > 0)
                left = max_v[i][j - 1];
            max_v[i][j] = max(left, up) + values[i][j];
        }
    }
    return max_v[rows - 1][cols - 1];
}

// 优化空间使用 只占用一行 即values[0].size()
int getMaxValue_v2(vector<vector<int>> values)
{
    if (values.size() == 0)
        return 0;
    if (values[0].size() == 0)
        return 0;
    int rows = values.size();
    int cols = values[0].size();

    vector<int> max_v(cols);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            int left = 0, up = 0;
            if (i > 0)
                up = max_v[j];
            if (j > 0)
                left = max_v[j - 1];
            max_v[j] = max(left, up) + values[i][j];
        }
    }
    return max_v[cols - 1];
}
