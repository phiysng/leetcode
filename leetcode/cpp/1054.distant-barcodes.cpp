class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        vector<int> res;
        unordered_map<int, int> map;
        if (barcodes.size() == 1)
            return {barcodes[0]};
        for (int i : barcodes)
        {
            if (map.find(i) == map.end())
            {
                map[i] = 1;
            }
            else
            {
                map[i]++;
            }
        }
        priority_queue<pair<int, int>> pq;
        for (pair<int, int> p : map)
        {
            pq.push(make_pair(p.second, p.first));
        }
        /// 不断获得剩余数量最大的 且 不同于前一个串的数值
        while (!pq.empty())
        {
            if (res.size() > 0 && res.back() == pq.top().second)
            {
                /// 相同的
                pair<int, int> t = pq.top();
                pq.pop();
                res.push_back(pq.top().second);
                pair<int, int> t_ = pq.top();
                t_.first--;

                pq.pop();
                if (t.first)
                    pq.push(t);
                if (t_.first)
                    pq.push(t_);
            }
            else
            {
                res.push_back(pq.top().second);
                pair<int, int> t = pq.top();
                t.first--;
                pq.pop();
                if (t.first)
                    pq.push(t);
            }
        }

        return res;
    }
};
