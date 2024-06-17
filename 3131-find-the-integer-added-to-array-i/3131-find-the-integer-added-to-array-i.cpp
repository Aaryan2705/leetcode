class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return (accumulate(nums2.begin(),nums2.end(),0)-accumulate(nums1.begin(),nums1.end(),0))/int(nums1.size());
    }
};