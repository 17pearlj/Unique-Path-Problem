class Solution {
public:
    bool isValidMove(int r, int c, vector<vector<int>>& grid ) {
        return (r < grid.size() && c < grid[0].size() && 
                r >= 0 && c >= 0 && 
                grid[r][c] != -1 && grid[r][c] != -2);
    }

    int uniquePathsIII(int r, int c, int walkCount, int desCount, vector<vector<int>> &grid) {

        if (r > grid.size() || c > grid[0].size() || r < 0 || c < 0) { return 0; }
        if (grid[r][c] == 2) {

            return (int)(desCount == walkCount);

        }
        int prev = grid[r][c];
        grid[r][c] = -2;
        int sum = 0;
        if (isValidMove(r+1, c, grid)) {
            sum += uniquePathsIII(r + 1, c, walkCount + 1, desCount, grid);
        }
        if (isValidMove(r-1, c, grid)) {
            sum += uniquePathsIII(r - 1, c, walkCount + 1, desCount, grid);
        }
        if (isValidMove(r, c-1, grid)) {
            sum += uniquePathsIII(r, c-1, walkCount + 1, desCount, grid);
        }
        if (isValidMove(r, c+1, grid)) {
            sum += uniquePathsIII(r, c+1, walkCount + 1, desCount, grid); 
        }
        grid[r][c] = prev;
        return sum;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int desCount = grid.size() * grid[0].size();
        vector<int> fin;
        vector<int> start;
        for (int r= grid.size()-1; r >= 0; r--) {
            for (int c = grid[0].size() - 1; c >= 0; c--) {
                if (grid[r][c] == 2) {
                    fin.push_back(r);
                    fin.push_back(c);
                } else if (grid[r][c] == 1) {
                    start.push_back(r);
                    start.push_back(c);
                    grid[r][c] = -2;
                } else if (grid[r][c] == -1) {
                    desCount--;
                }
            }
        }

        
        return uniquePathsIII(start[0], start[1], 1, desCount, grid);
        
    }
};
