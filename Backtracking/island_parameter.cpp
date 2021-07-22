class Solution {
public:

    int dfs(vector<vector<int>>& grid, int dx, int dy, int m, int n , vector<vector<int>>& visited)
    {
        if (dx == m or dy == n or dx < 0 or dy < 0 or grid[dx][dy] == 0)
            return 1;
        else if (visited[dx][dy] == 1)
            return 0;
        else
        {
            visited[dx][dy] = 1;
            int l = dfs(grid, dx - 1, dy, m, n, visited);
            int u = dfs(grid, dx, dy - 1, m, n, visited);
            int d = dfs(grid, dx, dy + 1, m, n, visited);
            int r = dfs(grid, dx + 1, dy, m, n, visited);

            return l + u + d + r;
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {

        int p = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector< vector<int>> visited(m , vector<int> (n, 0));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {

                    return dfs(grid, i, j, grid.size(), grid[0].size(), visited);

                }
            }

        }

        return -1;

    }
};