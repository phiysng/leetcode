import java.util.ArrayList;

enum STATE {
    ZERO,
    ONE,
    TWO,
    THREE
}

class Solution {
    public int longestSubarray(int[] nums) {

        int num = 0;
        var l = new ArrayList<Integer>();
        var ll = new ArrayList<ArrayList<Integer>>();
        STATE state = STATE.ZERO;
        for (int i = 0; i < nums.length; i++) {
            if (state == STATE.ZERO && nums[i] == 0) {
                continue;
            } else if (state == STATE.ZERO && nums[i] == 1) {
                state = STATE.ONE;
                num++;
            } else if (state == STATE.ONE && nums[i] == 1) {
                state = STATE.ONE;
                num++;
            } else if (state == STATE.ONE && nums[i] == 0) {
                state = STATE.TWO;
                l.add(num);
                num = 0;
            } else if (state == STATE.TWO && nums[i] == 1) {
                state = STATE.ONE;
                num++;

            } else if (state == STATE.TWO && nums[i] == 0) {
                state = STATE.THREE;
                ll.add(l);
                l = new ArrayList<>();
            } else if (state == STATE.THREE && nums[i] == 1) {
                state = STATE.ONE;
                num = 1;

            } else if (state == STATE.THREE && nums[i] == 0) {
                state = STATE.THREE;

            }
        }

        if (num != 0) {
            l.add(num);
        }
        if (!l.isEmpty()) {
            ll.add(l);
        }

        System.out.println(ll);

        if (ll.isEmpty()) {
            System.out.println(0);
            return 0;
        }

        int _max = 0;
        for (var list : ll) {
            if (list.size() == 0) {
                _max = Math.max(0, _max);
            } else if (list.size() == 1) {
                if(ll.size() == 1 &&list.get(0) ==nums.length){
                    _max = Math.max(list.get(0)-1, _max);
                }
                else {
                    _max = Math.max(list.get(0), _max);
                }

            } else {
                for (int i = 0; i < list.size() - 1; i++) {
                    _max = Math.max(list.get(i)+list.get(i+1),_max);
                }
            }

        }
        return _max;
    }
}
