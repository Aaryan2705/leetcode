class Solution {
public:
    // Function to find all unique combinations
    // of candidates that sum up to the target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Create a DP table where each index represents
        // a target from 0 to 'target'
        vector<vector<vector<int>>> dp(target + 1);
        // Base case: there's one way to make the sum 0
        // - with an empty combination
        dp[0].push_back({});

        // Iterate over all possible sums from 1 to 'target'
        for (int i = 1; i <= target; i++) {
            // Check each candidate to see if it can be used
            // to form the current sum 'i'
            for (int candidate : candidates) {
                // Only consider this candidate if it is not
                // greater than the sum 'i'
                if (candidate <= i) {
                    // Check all combinations that sum up to
                    // 'i - candidate'
                    for (auto& prev : dp[i - candidate]) {
                        // Create a new combination by adding
                        // the current candidate to it
                        vector<int> temp(prev);
                        temp.push_back(candidate);
                        // Sort to handle uniqueness (avoid duplicates)
                        sort(temp.begin(), temp.end());
                        // If this new combination is not already in dp[i],
                        // add it
                        if (std::find(dp[i].begin(), dp[i].end(), temp) ==
                            dp[i].end()) {
                            dp[i].push_back(temp);
                        }
                    }
                }
            }
        }
        // Return all combinations that sum up to 'target'
        return dp[target];
    }
};