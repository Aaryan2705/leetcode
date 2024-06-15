class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // if (nums.size() <= 1) return 0;         
        sort(nums.begin(), nums.end()); 
        
        int moves = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                int increment = nums[i - 1] - nums[i] + 1; 
                nums[i] = nums[i] + increment; 
                moves = moves + increment; 
            }
        }
        
        return moves;
    }
};