class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                    --k;
                    while (k > j && nums[k] == nums[k + 1])
                        --k;
                }
                else
                {
                    if (nums[i] + nums[j] + nums[k] > 0)
                    {
                        --k;
                    }
                    else
                    {
                        ++j;
                    }
                }
            }
        }
        return res;
    }
};