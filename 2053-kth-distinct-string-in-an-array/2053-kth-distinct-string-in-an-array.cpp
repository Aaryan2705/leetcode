class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int distinctCount = 0;

        for (int i = 0; i < arr.size(); ++i) {
            bool isDistinct = true;

            // Check if the string arr[i] is distinct
            for (int j = 0; j < arr.size(); ++j) {
                if (i != j && arr[i] == arr[j]) {
                    isDistinct = false;
                    break;
                }
            }

            // If distinct, increment the distinct count
            if (isDistinct) {
                distinctCount++;
                if (distinctCount == k) {
                    return arr[i];
                }
            }
        }

        // If there are fewer than k distinct strings
        return "";
    }
};