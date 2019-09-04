class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.size() <= 1) return nums.size();
        
        vector<int> res(nums.size(),1);
        
        for(int i = 1; i < nums.size();++i){
            int len = 1;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    len = max(len,res[j] + 1);
                }
            }
            res[i] = len;
            //cout << len<<endl;
        }
        int max_len  = 0;
        
        for_each(begin(res),end(res),[&max_len](int &i){
            max_len = max(max_len,i);
        });
        
        return max_len;
        
    }
};
