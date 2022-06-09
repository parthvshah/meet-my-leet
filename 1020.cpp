class Solution {
public: 
    int count(vector<vector<int>>& grid)
    {
        int m = grid.size();        // rows
        int n = grid[0].size();     // cols
        int count = 0;
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
    
    void flood(int x, int y, vector<vector<int>>& grid)
    {
        int m = grid.size();        // rows
        int n = grid[0].size();     // cols
        
        if(grid[x][y] == 1)
        {
            grid[x][y] = 0;
            
            if(x+1 < m && grid[x+1][y] == 1)
                flood(x+1, y, grid);
            if(x-1 >= 0 && grid[x-1][y] == 1)
                flood(x-1, y, grid);
            if(y+1 < n && grid[x][y+1] == 1)
                flood(x, y+1, grid);
            if(y-1 >= 0 && grid[x][y-1] == 1)
                flood(x, y-1, grid);

        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();        // rows
        int n = grid[0].size();     // cols
        
        for(int i = 0; i < m; ++i)
        {
            flood(i, 0, grid);
            flood(i, n-1, grid);
        }
        for(int i = 0; i < n; ++i)
        {
            flood(0, i, grid);
            flood(m-1, i, grid);
        }
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        
        return count(grid);
        
    }
};