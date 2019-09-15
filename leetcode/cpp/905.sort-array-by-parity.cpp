class Solution {
public:
    // 使用partition
    vector<int> sortArrayByParity(vector<int>& A) {
        int line = 0;
        for(int i = 0; i < A.size(); ++i){
            if(!(A[i] & 0x1)){
                swap(A[i],A[line++]);
            }
        }
        return A;
    }
};
