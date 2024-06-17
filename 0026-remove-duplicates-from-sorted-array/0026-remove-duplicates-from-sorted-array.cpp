class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int idx = 0;  // Index to track where to place the next unique element
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[idx]) {
                nums[++idx] = nums[i];  // Move unique elements to the front
            }
        }
        
        return idx + 1;  // Return the length of the resulting unique elements array
    }
};

