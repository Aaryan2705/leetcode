class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return (accumulate(nums2.begin(),nums2.end(),0)-accumulate(nums1.begin(),nums1.end(),0))/int(nums1.size());
    }
};
//17 ms below , 13 above
// public:
//     int addedInteger(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
//         int a = nums1[0];
//         int b = nums2[0];
//         if (a == b) return 0;
//         return b - a;
//     }
// };