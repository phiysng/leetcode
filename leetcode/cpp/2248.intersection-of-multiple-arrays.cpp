class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> map;
        for (auto& num_list : nums)
        {
            for (auto& n : num_list)
            {
                map[n]++;
            }
        }

        vector<int> r;

        for (auto& k : map)
        {
            if (k.second == nums.size())
            {
                r.push_back(k.first);
            }
        }

        sort(begin(r), end(r));
        return r;
    }
};