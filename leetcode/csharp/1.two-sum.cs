using System.Collections.Generic;

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> dict = new Dictionary<int,int>();
        for (int i = 0; i < nums.Length; i++)
        {
            if (dict.ContainsKey(target - nums[i]))
                return new int[] { i, dict[target - nums[i]] };
            else
                {
                    /// C#不允许重复add已经存在的键
                    if(!dict.ContainsKey(nums[i])){
                        dict.Add(nums[i],i);
                    }
                }
        }
        return new int[]{0,0};
    }
}
