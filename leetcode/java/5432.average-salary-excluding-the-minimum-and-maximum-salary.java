import java.util.Arrays;

class Solution {
    public double average(int[] salary) {

        int _max = Arrays.stream(salary).max().getAsInt();
        int _min = Arrays.stream(salary).min().getAsInt();
        int _sum = Arrays.stream(salary).sum();
        return (_sum - _max - _min) * 1.0 / (salary.length - 2);
    }
}
