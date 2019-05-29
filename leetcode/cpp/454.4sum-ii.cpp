class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
    {
        unordered_map<int, int> map;
        int cnt = 0;
        for (int i : A) {
            for (int j : B) {
                //写法并不推荐 但是简单
                map[i + j]++; //如果不存在键的话，会首先创建键并初始化值为零 ， 再++
            }
        }

        for (int i : C) {
            for (int j : D) {
                if (map.find(-(i + j)) != map.end()) {
                    cnt += map[-(i + j)];
                }
            }
        }

        return cnt;
    }
};