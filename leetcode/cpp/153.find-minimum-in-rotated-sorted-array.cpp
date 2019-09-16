class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] <= nums.back()) return nums.front();
        
        int l = 0 , r = nums.size()-1;
        while(l <= r){
            int mid = (l + r) /2;
            if(mid + 1 <= nums.size()-1 &&nums[mid] > nums[mid+1]) return nums[mid+1];
            if(mid -1 >= 0 && nums[mid] < nums[mid - 1]) return nums[mid]; //加了这一句反而慢了
            if(nums[mid] >= nums[l]){
                // 在左边子数组
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return 0;
    }
};