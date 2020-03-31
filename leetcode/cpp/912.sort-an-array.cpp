#include "oj_header.h"

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> res(nums);

        quick_sort(res, 0, res.size());

        return res;
    }
    /// \brief pivot at the right
    void quick_sort(vector<int> &nums, int _beg, int _end)
    {
        if (_end - _beg <= 1)
            return;

        int pivot = nums[_end - 1];

        int _idx = _beg;
        /// partition
        for (int i = _beg; i < _end - 1; ++i)
        {
            if (nums[i] < pivot)
            {
                swap(nums[_idx++], nums[i]);
            }
        }

        swap(nums[_end - 1], nums[_idx]);

        quick_sort(nums, _beg, _idx);
        quick_sort(nums, _idx + 1, _end);
    }
};