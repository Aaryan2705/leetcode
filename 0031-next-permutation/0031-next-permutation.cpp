class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // Step 1: Find the break point:
        int idx = -1; // Break point
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                // Index i is the break point
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            // Step 2: Find the next greater element and swap it with nums[idx]:
            for (int i = n-1; i > idx; i--) {
                if (nums[i] > nums[idx]) {
                    swap(nums[i], nums[idx]);
                    break;
                }
            }
        }
        // Reverse the right half
        reverse(nums.begin()+idx+1, nums.end());
    }
};