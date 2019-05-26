class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
    {
        int happy = 0;
        if (customers.size() <= 3 || X == 0)
        {
            int sum = 0;
            for (int i : customers)
                sum += i;
            return sum;
        }
        for (int i = 0; i < customers.size(); ++i)
        {
            if (grumpy[i] == 0)
            {
                happy += customers[i];
            }
        }
        int max_enhanced = 0;
        int i = 0;
        /// i < customers.size() -X +1
        vector<int> res(customers.size() - X + 1);
        int t = 0;
        for (int j = 0; j < X; ++j)
        {
            grumpy[j] ? t += customers[j] : 0;
        }
        res[0] = t;

        for (int k = 1; k < res.size(); ++k)
        {
            int v = res[k - 1];
            if (grumpy[k - 1])
                v -= customers[k - 1];
            if (grumpy[k + X - 1])
                v += customers[k + X - 1];
            res[k] = v;
        }

        return *max_element(res.begin(), res.end()) + happy;
    }
};
