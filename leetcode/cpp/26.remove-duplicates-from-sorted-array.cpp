class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int index = 0;
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[i - 1]) //不相同 指针右移
			{
				nums[++index] = nums[i];
			}
		}
		return index + 1;
	}
};
