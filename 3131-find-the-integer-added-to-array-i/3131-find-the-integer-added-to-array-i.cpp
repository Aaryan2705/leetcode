class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int a = nums1[0];
        int b = nums2[0];
        if (a == b) return 0;
        return b - a;
    }
};