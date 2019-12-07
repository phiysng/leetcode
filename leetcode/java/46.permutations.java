import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

// 回溯法
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backtrace(nums, 0, res);

        return res;
    }

    private void backtrace(int[] nums, int i, List<List<Integer>> res) {
        if (i == nums.length - 1) {
            res.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));
            System.out.println(Arrays.toString(nums));
            return;
        }

        for (int k = i ; k < nums.length; k++) {
            swap(nums, i, k);
            backtrace(nums, i + 1, res);
            swap(nums, i, k);
        }
    }

    private void swap(int[] nums, int l, int r) {
        int t = nums[l];
        nums[l] = nums[r];
        nums[r] = t;
    }
}
