/* 
64.最小路径和
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(i == 0 && j == 0) continue;
                else if(i == 0 && j > 0) grid[i][j] = grid[i][j-1] + grid[i][j]; // 说明在第一行，只能从左边往右走
                else if(j == 0 && i > 0) grid[i][j] = grid[i-1][j] + grid[i][j]; // 说明在第一列，只能从上边往下走
                else grid[i][j] = min(grid[i-1][j],grid[i][j-1]) + grid[i][j]; // 取从左边走，或从上边走的较小者
            }
        }

        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};