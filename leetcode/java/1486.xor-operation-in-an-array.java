class Solution {
    public int xorOperation(int n, int start) {
        int r = start;
        for (int i = 1; i < n; i++) {
            r ^= (start+i*2);
        }
        return r;
    }
}
