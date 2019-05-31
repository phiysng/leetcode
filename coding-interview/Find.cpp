// 4 二维数组中的查找

// 数组的右面的数大于左面的数 下面的数大于上面的数

//amtrix[i][j] < col[k] 它小于k列及其右边的列
//amtrix[i][j] > row[k] 上面的[0-k]列也都是更小的

bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;

    if (matrix && rows > 0 && columns > 0) {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0) {
            if (matrix[row * columns + column] == number) {
                found = true;
                break;
            } else {
                if (matrix[row * columns + column] > number) {
                    --column;
                } else {
                    ++row;
                }
            }
        }
    }
    return found;
}
