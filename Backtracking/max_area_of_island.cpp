class Solution {
public:
    int max(int x, int y)
    {
        return x > y ? x : y;
    }
    int fun(vector<vector<int>>& grid, int i, int j)
    {
        if (i<0 or i >= grid.size() or j<0 or j >= grid[i].size() or grid[i][j] == 0 or grid[i][j] == 2)
            return 0;
        else
        {
            grid[i][j] = 2;
            int u = fun(grid, i - 1, j);
            int d = fun(grid, i + 1, j);
            int l = fun(grid, i, j - 1);
            int r = fun(grid, i, j + 1);

            return 1 + u + d + l + r;
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int max_area = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int new_area = fun(grid, i, j);
                    max_area = max(max_area, new_area);
                }
            }
        }

        return max_area;

    }
};