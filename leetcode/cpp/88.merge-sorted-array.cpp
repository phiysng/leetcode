class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int r = n - 1;
        int l = m - 1;

        for (int i = nums1.size() - 1; i >= 0; --i) {
            if (l >= 0 && r >= 0) {
                if (nums1[l] > nums2[r]) {
                    nums1[i] = nums1[l--];
                } else {
                    nums1[i] = nums2[r--];
                }
            } else {
                if (l >= 0) {
                    nums1[i] = nums1[l--];
                } else {
                    nums1[i] = nums2[r--];
                }
            }
        }
    }
};
