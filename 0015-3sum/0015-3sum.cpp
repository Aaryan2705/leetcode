class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Iterate through each element as the first element of the triplet
        for (int i = 0; i < n - 2; ++i) {
            // Avoid duplicates for nums[i]
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int target = -nums[i];  // find two sum that equals to target
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate values of nums[left]
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    
                    // Skip duplicate values of nums[right]
                    while (left < right && nums[right] == nums[right - 1])
                        --right;
                    
                    // Move pointers to find next unique triplet
                    ++left;
                    --right;
                }
            }
        }
        
        return result;
    }
};