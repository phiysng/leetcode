class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes)
    {
        // 工人到点对的距离
        vector<vector<int>> distance(workers.size(), vector<int>(bikes.size()));
        for (int i = 0; i < workers.size(); ++i) {
            for (int j = 0; j < bikes.size(); ++j) {
                distance[i][j] = distance_(workers[i], bikes[j]);
            }
        }

        vector<int> visited(bikes.size());
        int init_min_dis = 0;
        for (int i = 0; i < workers.size(); ++i) {
            init_min_dis += distance[i][i];
        }
        for (int k = 0; k < visited.size(); ++k) {

            search(distance, visited, 0, 0, workers.size(), k, init_min_dis);
        }
        return init_min_dis;
    }
    //距离 是否访问 当前距离 当前回溯/递归的层数 剩余的层数 当前指向的列 当前获得的最小的距离
    // level与n重复了实际上
    void search(vector<vector<int>>& dis, vector<int>& visited, int curr_dis, int level, int n, int idx, int& min_dis)
    {
        if (n == 1) {
            min_dis = min(curr_dis + dis[level][idx], min_dis);
            return;
        }
        visited[idx] = 1;
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                //递归
                search(dis, visited, curr_dis + dis[level][idx], level + 1, n - 1, i, min_dis);
            }
        }
        visited[idx] = 0;
    }

    int distance_(vector<int>& a, vector<int>& b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};
