class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int j = 1;
        int count = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                if (count < 2) {
                    nums[j] = nums[i];
                    j++;
                    count++;
                }
            } else {
                nums[j] = nums[i];
                j++;
                count = 1;
            }
        }

        return j;
    }
};