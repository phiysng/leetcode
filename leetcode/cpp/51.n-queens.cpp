#include "oj_header.h"

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        _n = n;
        cols.resize(n + 1);
        major_diagonal.resize(n * 2 - 1);
        minor_diagonal.resize(n * 2 - 1);

        back_track();
        return res;
    }

    bool valid_position(int row, int col)
    {
        return !(cols[col] + major_diagonal[row - col + _n - 1] + minor_diagonal[row + col]);
    }

    void set_position(int row, int col)
    {
        cols[col] = 1;
        // TODO: see python impl for details.
        major_diagonal[row - col + _n - 1] = 1;
        minor_diagonal[row + col] = 1;
    }

    void unset_position(int row, int col)
    {
        cols[col] = 0;
        major_diagonal[row - col + _n - 1] = 0;
        minor_diagonal[row + col] = 0;
    }

    void push_res()
    {
        vector<string> t;
        for (int i = 0; i < queue.size(); ++i)
        {
            t.push_back(string(queue[i].second, '.') + "Q" +
                        string(_n - queue[i].second - 1, '.'));
        }
        res.push_back(t);
    }

    void back_track(int row = 0)
    {
        for (int col = 0; col < _n; ++col)
        {
            if (valid_position(row, col))
            {
                queue.push_back(make_pair(row, col));
                set_position(row, col);
                if (row + 1 == _n)
                {
                    // valid position
                    push_res();
                }
                else
                {
                    back_track(row + 1);
                }
                queue.pop_back();
                unset_position(row, col);
            }
        }
    }

private:
    int _n;
    vector<pair<int, int>> queue;
    vector<vector<string>> res;
    vector<int> cols;
    vector<int> major_diagonal;
    vector<int> minor_diagonal;
};
