class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n < 5){
            return 0 ;
        }
        sort(nums.begin(),nums.end());
        int min_diff = INT_MAX;
        min_diff = min(min_diff, nums[n - 4] - nums[0]);   // Ignore 0 smallest and 3 largest
        min_diff = min(min_diff, nums[n - 3] - nums[1]);   // Ignore 1 smallest and 2 largest
        min_diff = min(min_diff, nums[n - 2] - nums[2]);   // Ignore 2 smallest and 1 largest
        min_diff = min(min_diff, nums[n - 1] - nums[3]);
        
        return min_diff ;
        
    }
};