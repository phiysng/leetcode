class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        if (nums.size() < 4)
            return {};
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            if (i != 0)
            {
                if (nums[i] == nums[i - 1])
                    continue;
            }
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j != i + 1)
                {
                    if (nums[j] == nums[j - 1])
                        continue;
                }
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    int x = nums[i] + nums[j] + nums[l] + nums[r]; //当前结果
                    if (x == target)
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                        while (l < r && nums[l] == nums[l - 1])
                            ++l;
                        while (l < r && nums[r] == nums[r + 1])
                            --r;
                    }
                    else
                    {
                        if (x < target)
                        {
                            ++l;
                        }
                        else
                        {
                            --r;
                        }
                    }
                }
            }
        }
        return res;
    }
};
