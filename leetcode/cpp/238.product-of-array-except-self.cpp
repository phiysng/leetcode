class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> res(nums.size(), 1);

        //从左往右的乘积
        int v = 1;
        //第一个数字无需计算 最后一个的乘积由前n-1个获得
        for (int i = 0; i < nums.size() - 1; ++i) {
            v *= nums[i];
            res[i + 1] = v;
        }
        
        //从右往左的乘积
        // 同上 忽略第n个乘积的计算,第一个乘积的结果由后n-1个获得
        v = 1;
        for (int i = nums.size() - 1; i > 0; --i) {
            v *= nums[i];

            res[i - 1] *= v;
        }
        return res;
    }
};