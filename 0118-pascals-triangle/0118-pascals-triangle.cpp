class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1); // Create a new row with i+1 elements, all initialized to 1
            
            // Fill the row excluding the first and last elements
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            triangle.push_back(row); // Add the current row to the triangle
        }
        
        return triangle;
    }
};