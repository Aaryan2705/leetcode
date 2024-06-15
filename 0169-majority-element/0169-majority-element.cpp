class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        const int size = nums.size();

        // Loop unrolling for potential minor performance gains
        for (int i = 0; i < size; ++i) {
            if (count == 0) {
                candidate = nums[i];
            }
            count += (nums[i] == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
