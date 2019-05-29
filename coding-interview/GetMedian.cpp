///数据流中的中位数

#include "array_util.h"
using namespace std;

template <typename T>
class DynamicArray {
private:
    vector<T> min_;
    vector<T> max_;

public:
    DynamicArray();
    ~DynamicArray();
    void Insert(T num);
    T GetMedian();
};

template <typename T>
DynamicArray<T>::DynamicArray() {}

template <typename T>
DynamicArray<T>::~DynamicArray() {}

template <typename T>
void DynamicArray<T>::Insert(T num)
{
    ///最小堆中所有的数字都大于最大堆中所有的数字
    /// min[0] <= min[1...]
    /// max[0] >= max[1...]

    /// 如果说 数字是奇数个数字 将之放入min_中
    /// 特别的 如果这个数字不比所有的最大堆中的数据都大(存在数大于这个num)，
    /// 需要与max_中当前最大的数字置换
    if (((min_.size() + max_.size()) & 1) == 0) {
        if (max_.size() > 0 && num < max[0]) {
            max_.push_back(num);
            push_heap(max_.begin(), max_.end(), less<T>()); ///最大堆增加元素

            num = max_[0];

            pop_heap(max.begin(), max.end(), less<T>());
            max_.pop_back();
        }
        ///
        min_.push_back(num);
        push_heap(min_.begin(), min_.end(), greater<T>());
    }
    
    /// 如果当前要压入堆中的是偶数个(2,4,6...)数字，将之压入max_,
    /// 特别的 如果这个数字不比min_中的所有数字都小
    /// 则需要将当前min_中最小的数与之交换
    else {
        if (min_.size() > 0 && min_[0] < num) {
            min_.push_back(num);
            push_heap(min_.begin(), min_.end(), greater<T>());

            num = min_[0]; //交换完成

            pop_heap(min_.begin(), min_.end(), greater<T>());
            min_.pop_back();
        }
        max_.push_back(num);
        push_heap(max_.begin(), max_.end(), less<T>());
    }
}
template <typename T>
T DynamicArray<T>::GetMedian()
{
    int size = min_.size() + max_.size();
    if (size == 0)
        throw exception("No Numbers are available.");
    T median = 0;
    if (size & 1) // odd
    {
        midian = min_[0];
    } else {
        median = (min_[0] + max_[0]) / 2;
    }
    return median;
}
