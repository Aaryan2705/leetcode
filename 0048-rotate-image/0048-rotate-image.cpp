class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> rotate(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                rotate[j][i] = matrix[i][j];
        }
        for(int i=0; i<n; i++)
            reverse(rotate[i].begin(), rotate[i].end());
        matrix = rotate;
    }
};