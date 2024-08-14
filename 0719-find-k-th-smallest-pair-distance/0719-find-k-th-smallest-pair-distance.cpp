class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countPairs(nums, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }

private:
    int countPairs(const std::vector<int>& nums, int distance) {
        int count = 0, left = 0;
        for (int right = 1; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > distance) {
                ++left;
            }
            count += right - left;
        }
        return count;
    }
};
