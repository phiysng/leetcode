#include "oj_header.h"

/**
 * @brief Binary Indexed Tree / Fenwick Tree template.
 * 
 * use array to represent a tree , 
 * it need to be as big as our biggest number of this array can be.
 * aka , [1,10.4] , we need a array of [0] * 11.
 * we use the index to represent the existence of the number.
 * and the value of the index to indicate the freq of this number.
 * eg , arr[4] = 2 means we have number 4 twice , like [4,2,3,4].
 * 
 * then we can update or query the number of the value of this partial
 * list , with a O(log(m)) time complexisity.
 * 
 */
class FenwickTree
{
public:
    FenwickTree(int n) : sum_(n + 1, 0) {}

    void update(int i ,int delta){
        while(i < sum_.size()){
            sum_[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) const{
        int sum = 0;
        while(i > 0){
            sum += sum_[i];
            i -= lowbit(i);
        }

        return sum;
    }

private:
    static inline int lowbit(int x){
        return x & (-x);
    }

    vector<int> sum_;
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int n = instructions.size();
        FenwickTree tree(1e5);
        int64_t ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            // index更新时不断向前query
            // 小于自己的数
            int lt = tree.query(instructions[i]-1);
            // 小于等于自己的数的相反就是大于自己的数
            int gt = i - tree.query(instructions[i]);
            ans += min(lt , gt);
            tree.update(instructions[i],1);
        }

        return ans % 1000000007;
        
    }
};