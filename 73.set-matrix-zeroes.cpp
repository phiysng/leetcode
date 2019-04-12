class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        if(matrix[0].size() == 0) return;
        vector<int> row(matrix.size());//列
        vector<int> col(matrix[0].size());//行
        
        for(int i = 0 ; i < matrix.size() ; ++i){
            // bool flag = false;
            for(int j = 0 ; j < matrix[0].size(); ++j){
                if(matrix[i][j] ==0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
            // if(true)
        }
        for(int i = 0 ; i < row.size();++i)
        {
            if(row[i])
                setZero_Row(matrix,i);
        }
         for(int i = 0 ; i < col.size();++i)
         {
            if(col[i])
                setZero_Col(matrix,i);
         }
        
    }
    void setZero_Row(vector<vector<int>>& matrix , int row){
        for(int i = 0 ; i < matrix[0].size();++i){
            matrix[row][i] = 0;
        }
    }
    void setZero_Col(vector<vector<int>>& matrix , int col){
        for(int i = 0 ; i < matrix.size();++i){
            matrix[i][col] = 0;
        }
    }
};