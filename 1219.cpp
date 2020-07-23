class Solution {
public:
    int bt(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]<=0)
            return 0;
        grid[i][j] *= -1;
        
        auto res = max({bt(grid, i-1, j), bt(grid, i, j-1), bt(grid, i+1, j), bt(grid, i, j+1)});
        grid[i][j] *= -1;
        
        return grid[i][j] + res;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        int _max = INT_MIN;
        
        for(int i = 0; i<grid.size(); ++i)
        {
            for(int j = 0; j<grid[i].size(); ++j)
            {
                if(grid[i][j]!=0)
                    res = bt(grid, i, j);
                
                if(res>_max)
                    _max = res;
            }
        }
        
        return _max;
    }
};