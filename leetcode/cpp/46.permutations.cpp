class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> vv{ nums };

        for (int i = 0; i < nums.size() - 1; ++i) { //交换的位置
            int _size = vv.size();
            for (int j = 0; j < _size; ++j) { //遍历当前的所有答案
                for (int k = i + 1; k < nums.size(); ++k) { //将[i+1,nums.size()-2]的位置都与i交换
                    vector<int> v = vv[j];
                    swap(v[i], v[k]);
                    vv.push_back(v); //存入结果
                }
            }
        }
        return vv;
    }
};
