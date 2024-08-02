class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0); // Total number of 1's in the array
        int n = nums.size();
        
        // If there are no 1's, no swaps are needed
        if (total == 0) {
            return 0;
        }
        
        // Extend the array to handle the circular nature
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        // Initialize the sliding window
        int window_sum = accumulate(nums.begin(), nums.begin() + total, 0);
        int max_ones = window_sum;
        int swaps = total - max_ones;
        
        for (int i = 1; i < n; ++i) {
            // Update the number of 1's in the current window by sliding the window
            window_sum += nums[i + total - 1] - nums[i - 1];
            max_ones = max(max_ones, window_sum);
            swaps = min(swaps, total - max_ones);
        }
        
        return swaps;
    }
};