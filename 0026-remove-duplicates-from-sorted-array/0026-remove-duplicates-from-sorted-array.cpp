class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0 ;
        }
        int ans = 0 ;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[ans]) {
                nums[++ans] = nums[i];
            }
        }
        
        return ans + 1 ;
    }
};


