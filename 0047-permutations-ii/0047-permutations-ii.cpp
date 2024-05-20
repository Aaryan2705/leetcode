class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> nums, int start){
        if(start==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(i==start || nums[start]!=nums[i]){
                swap(nums[start],nums[i]);
                helper(nums,start+1);
            }
        }
        
    }  
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int start=0;
        sort(nums.begin(), nums.end());
        helper(nums,start);
        return res;
    }
};