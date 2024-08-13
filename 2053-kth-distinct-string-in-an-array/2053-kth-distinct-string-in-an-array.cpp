class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // Loop through the array to find the distinct strings
        for (int i = 0; i < arr.size(); i++) {
            int count = 0;
            // Check how many times the string appears in the array
            for (int j = 0; j < arr.size(); j++) {
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
            // If the string appears exactly once, it's distinct
            if (count == 1) {
                k--; // Reduce k for each distinct string found
                if (k == 0) {
                    return arr[i]; // Return the kth distinct string
                }
            }
        }
        // If fewer than k distinct strings are found, return an empty string
        return "";
    }
};