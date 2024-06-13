class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redPtr = 0; 
        int bluePtr = nums.size() - 1; 
        int i = 0; 
        
        while (i <= bluePtr) {
            if (nums[i] == 0) {
                swap(nums[i], nums[redPtr]); 
                redPtr++; 
                i++; 
            } else if (nums[i] == 2) {
                swap(nums[i], nums[bluePtr]); 
                bluePtr--; 
            } else {
                i++; 
            }
        }
    }
};