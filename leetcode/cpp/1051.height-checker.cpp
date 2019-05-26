class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> cp = heights;
        sort(cp.begin(), cp.end());
        int cnt = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            if (cp[i] != heights[i])
                ++cnt;
        }
        return cnt;
    }
};
