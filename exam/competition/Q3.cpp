class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int rowSize = grid.size(), colSize = grid[0].size();
        vector<vector<long long>>dpMax(rowSize, vector<long long>(colSize));
        vector<vector<long long>>dpMin(rowSize, vector<long long>(colSize));
        //初始化
        dpMax[0][0] = grid[0][0];
        dpMin[0][0] = grid[0][0];
        for(int i = 1; i < rowSize; i++){
            dpMax[i][0] = dpMax[i-1][0] * grid[i][0];
            dpMin[i][0] = dpMin[i-1][0] * grid[i][0];
        }
        for(int i = 1; i < colSize; i++){
            dpMax[0][i] = dpMax[0][i-1] * grid[0][i];
            dpMin[0][i] = dpMin[0][i-1] * grid[0][i];
        }
        for(int i = 1;i < rowSize; i++){
            for(int j = 1; j < colSize; j++){
                dpMax[i][j] = max({
                    dpMax[i-1][j] * grid[i][j],
                    dpMax[i][j-1] * grid[i][j],
                    dpMin[i-1][j] * grid[i][j],
                    dpMin[i][j-1] * grid[i][j]
                });
                dpMin[i][j] = min({
                    dpMax[i-1][j] * grid[i][j],
                    dpMax[i][j-1] * grid[i][j],
                    dpMin[i-1][j] * grid[i][j],
                    dpMin[i][j-1] * grid[i][j]
                });
            }
        }
        return dpMax[rowSize-1][colSize-1] < 0 ? -1 : dpMax[rowSize-1][colSize-1] % 1000000007;
    }
};