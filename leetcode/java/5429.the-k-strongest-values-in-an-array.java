import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

class Solution {
    public int[] getStrongest(int[] arr, int k) {
        Arrays.sort(arr);
        int m = (arr.length - 1) / 2;
        int v = arr[m];
        // we need a list of pair and sort it.
        List<List<Integer>> listOfPair = new ArrayList<>();

        for (int value : arr) {
            listOfPair.add(List.of(Math.abs(value - v), value));
        }
        listOfPair.sort((a, b) -> {
            if (!a.get(0).equals(b.get(0)))
                return b.get(0) - a.get(0);
            else
                return b.get(1) - a.get(1);
        });

        return listOfPair.stream().limit(k).mapToInt(i -> i.get(1)).toArray();
    }
}
