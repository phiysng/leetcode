#include "oj_header.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int>(n));
        
        int l = 0, r = n , t = 0 , b = n;
        int cnt = 1;
        while(cnt <= n*n){
            for(int i = l; i < r;++i){
                arr[t][i]=cnt++;
            }
           
            for(int i = t + 1; i < b;++i){
                arr[i][r-1]=cnt++;
            }
            
            for(int i = r - 2; i >= l;--i){
                arr[b-1][i] = cnt++;

            }
            
            for(int i = b -2; i > t; --i){
                arr[i][l] = cnt++;
            }
            ++t;
            --r;
            --b;
            ++l;
        }
        return arr;
    }
};
