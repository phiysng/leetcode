import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        Arrays.sort(horizontalCuts);
        Arrays.sort(verticalCuts);
        // 可以尝试在上面两个数组增加0和h/w,从而可以简化下面的代码
        List<Integer> hor = new ArrayList<>();
        hor.add(horizontalCuts[0]);
        List<Integer> ver = new ArrayList<>();
        ver.add(verticalCuts[0]);


        for (int i = 0; i < horizontalCuts.length - 1; i++) {
            hor.add(horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        hor.add(h - horizontalCuts[horizontalCuts.length - 1]);

        for (int i = 0; i < verticalCuts.length - 1; i++) {
            ver.add(verticalCuts[i + 1] - verticalCuts[i]);
        }
        ver.add(w - verticalCuts[verticalCuts.length - 1]);


        long m1 = hor.stream().max(Integer::compareTo).get();
        long m2 = ver.stream().max(Integer::compareTo).get();

        int cast = (1000000000 + 7);
        return (int) ((long) (m1) * ((long) m2) % cast);

    }
}
