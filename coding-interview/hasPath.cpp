// 12 矩阵中的路径

#include "array_util.h"
using namespace std;

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
    if (str[pathLength] == '\0')
        return true;

    bool hasPath = false;
    //合法的[][] 并且是相同的char c
    if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col]) {
        ++pathLength;
        visited[row * cols + col] = true;

        hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);

        // 当前情况失败 回溯backtrack
        if (!hasPath) {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }

    return hasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if (!matrix || rows < 1 || cols < 1 || !str)
        return nullptr;
    bool* visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    int pathLength = 0;
    // 遍历所有可能的开始节点
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; ++col) {
            if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)) {
                return true;
            }
        }
    }
    delete[] visited;

    return false;
}
