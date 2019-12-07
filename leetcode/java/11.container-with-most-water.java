class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length - 1;

        int cubes = 0;

        while (l < r) {
            cubes = Math.max(Math.min(height[l], height[r]) * (r - l),cubes);
            if(height[l] < height[r]){
                ++l;
            }
            else {
                --r;
            }
        }

        return cubes;
    }
}
