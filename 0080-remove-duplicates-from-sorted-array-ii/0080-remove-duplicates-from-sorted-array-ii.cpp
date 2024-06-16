class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // If there are 0, 1, or 2 elements, no need to remove anything
        
        int j = 1; // Pointer to where the next unique element should be placed
        int count = 1; // Count of the current element being processed, starting with the first occurrence
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                if (count < 2) {
                    // We can place another occurrence of nums[i]
                    nums[j] = nums[i];
                    ++j;
                    ++count;
                }
                // If count == 2, we skip nums[i] (it's a duplicate beyond the second occurrence)
            } else {
                // nums[i] is a new element
                nums[j] = nums[i];
                ++j;
                count = 1; // Reset count for the new element
            }
        }
        
        return j;
    }
};