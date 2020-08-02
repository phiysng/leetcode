#include "oj_header.h"

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &M)
    {
        if (M.empty() || M[0].empty())
            return 0;

        QuickUnion qu(M.size());
        for (int i = 0; i < M.size(); ++i)
        {
            for (int j = 0; j < M[i].size(); ++j)
            {
                if (M[i][j])
                {
                    qu.Union(i, j);
                }
            }
        }
        return qu.size();
    }

    class QuickUnion
    {
    public:
        explicit QuickUnion(int size) : parents(size), size_(size)
        {
            for (int i = 0; i < size_; ++i)
            {
                parents[i] = i;
            }
        }
        void Union(int i, int j)
        {
            int rootI = find(i);
            int rootJ = find(j);
            // j turn its root to i
            if (rootI != rootJ)
            {
                parents[rootJ] = rootI;
                --size_;
            }
        }
        int size()
        {
            return size_;
        };

    private:
        int find(int id)
        {
            int id_;
            while ((id_ = parents[id]) != id)
            {
                id = id_;
            }

            return id_;
        }
        vector<int> parents;
        int size_;
    };
};