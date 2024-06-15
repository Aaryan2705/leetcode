class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Base cases:
        if (numRows == 0) return {};         // If numRows is 0, return an empty vector of vectors
        if (numRows == 1) return {{1}};      // If numRows is 1, return a vector with one vector containing {1}
        
        // Recursive call to generate Pascal's Triangle for numRows-1
        vector<vector<int>> prevRows = generate(numRows - 1);
        
        // Create a new row with numRows elements, all initialized to 1
        vector<int> newRow(numRows, 1);
        
        // Fill the newRow excluding the first and last elements
        for (int i = 1; i < numRows - 1; i++) {
            // Calculate each element based on the previous row
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        }
        
        // Add the newly generated row to the previous rows
        prevRows.push_back(newRow);
        
        // Return the updated triangle
        return prevRows;
    }
};