class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int target = -nums[i];
            int left = i + 1, right = n - 1;
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // Skip duplicates of nums[left]
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // Skip duplicates of nums[right]
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
        
        return result;
    }
};