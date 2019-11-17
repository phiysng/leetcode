// 递归版本
class Solution_v1
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> v;
        backtrace(0, nums.size(), v, nums);

        return v;
    }

    void backtrace(int first, int n, vector<vector<int>> &res, vector<int> &t)
    {
        if (n == first)
        {
            res.push_back(t);
            return;
        }

        for (int i = first; i < n; ++i)
        {
            swap(t[first], t[i]);
            backtrace(first + 1, n, res, t);

            swap(t[first], t[i]);
        }
    }
};

class Solution_v2
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> vv{nums};

        for (int i = 0; i < nums.size() - 1; ++i)
        { //交换的位置
            int _size = vv.size();
            for (int j = 0; j < _size; ++j)
            { //遍历当前的所有答案
                for (int k = i + 1; k < nums.size(); ++k)
                { //将[i+1,nums.size()-2]的位置都与i交换
                    vector<int> v = vv[j];
                    swap(v[i], v[k]);
                    vv.push_back(v); //存入结果
                }
            }
        }
        return vv;
    }
};
