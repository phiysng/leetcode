import java.util.ArrayList;

class Solution {
    public int[] shuffle(int[] nums, int n) {
        var x = new ArrayList<Integer>();
        var y = new ArrayList<Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (i < n) {
                x.add(nums[i]);
            } else {
                y.add(nums[i]);
            }
        }

        var r = new ArrayList<Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (i % 2 == 0) {
                r.add(x.get(i / 2));
            } else {
                r.add(y.get(i / 2));

            }
        }

        return r.stream().mapToInt(i -> i).toArray();
    }
}
