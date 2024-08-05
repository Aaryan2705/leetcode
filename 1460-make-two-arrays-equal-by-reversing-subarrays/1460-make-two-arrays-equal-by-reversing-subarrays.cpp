class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Sort both arrays
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        // Compare the sorted arrays
        return target == arr;
    }
};