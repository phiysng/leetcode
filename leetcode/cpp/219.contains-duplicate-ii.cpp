class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int max_dis = 0;
        
        unordered_map<int,int> map;//第一次出现的位置
        
        for(int i = 0 ; i < nums.size();++i){
            if(map.find(nums[i]) == map.end()){ //第一次出现
                map[nums[i]] = i;
            }
            else{
                if(i - map[nums[i]] <= k){
                    return true;
                }
                map[nums[i]] = i;
            }
            
        }
        return false;
    }
};
