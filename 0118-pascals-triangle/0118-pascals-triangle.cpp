class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return {};
        }
        else if ( numRows == 1) {
            return{{1}};
        }
        vector<vector<int>> prevRow = generate(numRows-1);
        vector<int> row(numRows , 1);
        for (int i = 1 ; i < row.size()-1 ; i++){
            row[i] = prevRow.back()[i-1] + prevRow.back()[i];
        }
        prevRow.push_back(row) ;
        return prevRow ;
    }
};