class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int row, int col, int n,
                 int expval) {
        if (row < 0 || col < 0 || row >= n || col >= n ||
            grid[row][col] != expval) {
            return false;
        }
        if (expval == (n * n - 1)) {
            return true;
        }
        int ans1 = isValid(grid, row - 2, col + 1, n, expval + 1);
        int ans2 = isValid(grid, row - 1, col + 2, n, expval + 1);
        int ans3 = isValid(grid, row + 1, col + 2, n, expval + 1);
        int ans4 = isValid(grid, row + 2, col + 1, n, expval + 1);
        int ans5 = isValid(grid, row + 2, col - 1, n, expval + 1);
        int ans6 = isValid(grid, row + 1, col - 2, n, expval + 1);
        int ans7 = isValid(grid, row - 1, col - 2, n, expval + 1);
        int ans8 = isValid(grid, row - 2, col - 1, n, expval + 1);
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};