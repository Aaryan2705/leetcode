class Solution {
private:
    void fillRegion(vector<vector<int>> &regions, int r, int c, char ch){
        if(ch == '/'){
            regions[3*r][3*c + 2] = 1;
            regions[3*r + 1][3*c + 1] = 1;
            regions[3*r + 2][3*c] = 1;
        }
        else if(ch == '\\'){
            regions[3*r][3*c] = 1;
            regions[3*r + 1][3*c + 1] = 1;
            regions[3*r + 2][3*c + 2] = 1;
        }
    }
    void bfs(vector<vector<int>> &regions, int r, int c){
        int rows = regions.size();
        int cols = regions[0].size();
        vector<int> dr[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        regions[r][c] = 1;
        q.push({r, c});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            for(auto &ele : dr){
                int tempR = ele[0] + front.first;
                int tempC = ele[1] + front.second;
                if(tempR >= 0 and tempR < rows and tempC >= 0 and tempC < cols and regions[tempR][tempC] == 0){
                    regions[tempR][tempC] = 1;
                    q.push({tempR, tempC});
                }
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // \\
        // " "/
        // /" "
        // Magnified into 3*3 grid
        // For an empty space
        // 0 0 0 
        // 0 0 0
        // 0 0 0

        // For the /
        // The grid will be
        // 0 0 1
        // 0 1 0
        // 1 0 0

        // For the \\
        // The grid will be
        // 1 0 0 
        // 0 1 0 
        // 0 0 1

        // Example
        // 0 0 0 0 0 1
        // 0 0 0 0 1 0
        // 0 0 0 1 0 0
        // 0 0 1 0 0 0
        // 0 1 0 0 0 0
        // 1 0 0 0 0 0
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> regions(3 * rows, vector<int> (3 * cols, 0));
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                fillRegion(regions, i, j, grid[i][j]);
            }
        }
        int answer = 0;
        for(int i = 0 ; i < 3 * rows ; i++){
            for(int j = 0 ; j < 3 * cols ; j++){
                if(regions[i][j] == 0){
                    answer += 1;
                    bfs(regions, i, j);
                }
            }
        }
        return answer;
    }
};