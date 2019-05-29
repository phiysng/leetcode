/// 最小的k个数
#include "array_util.h"

using namespace std;
/**
 * 比较
 * ----------------------
 * |         | v1 |  v2 |
 * |修改数组 |  √ |  ×  |
 * |海量数据 |  × |  √  |
 */

void GetLeastNumbers_v1(int* input, int n, int* output, int k)
{
    if (input == nullptr || output == nullptr || k > n || k <= 0 || n <= 0)
        return;
    int start = 0, end = n - 1;
    int index = Partition(input, n, start, end);
    while (index != k - 1) //index没有正好将前k-1个数划分好
    {
        if (index > k - 1) {
            end = index - 1;

        } else ///划分的前半部分的数字数量不够
        {
            start = index + 1;
        }
        index = Partition(input, n, start, end);
    }
    for (int i = 0; i < k; i++) {
        output[i] = input[i];
    }
}

// 使用优先队列 O(nlog(k))
// assert data is valid.
vector<int> GetLeastNumbers_v2(const vector<int>& data, int k)
{
    if (k < 1 || data.size() < k)
        return {};

    priority_queue<int> pq; //默认为最大堆

    for (int i : data) {
        pq.push(i);
        if (pq.size() > k)
            pq.pop();
    }
    vector<int> res;
    res.reserve(k);
    while (!pq.empty()) {
        res.emplace_back(pq.top());
        pq.pop();
    }
    return res;
}
