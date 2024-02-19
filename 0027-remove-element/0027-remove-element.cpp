class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0;
        int j = nums.size() - 1;
        for (int i = 0; i <= j; i++) {
            if (nums[i] == val) {
                std::swap(nums[i], nums[j]);
                j--;
                i--;
            } else {
                k++;
            }
        }
        return k;
    }
};