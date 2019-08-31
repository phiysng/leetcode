struct CompareBySecond {
    constexpr bool operator()(pair<int, int> const& a,
        pair<int, int> const& b) const noexcept
    {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> map;

        for (int i : nums) {
            map[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareBySecond> pq;

        for (auto& i : map) {
            pq.push(i);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;

        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
