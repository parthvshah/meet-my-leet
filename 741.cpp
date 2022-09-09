class Solution {
public:
    int solve(int x1, int y1, int x2, int y2,
             vector<vector<int>> &grid, unordered_map<int, int> &umap)
    {
        int n = grid.size();
        
        if(x1 >= n || y1 >= n || x2 >= n || y2 >= n || grid[x1][y1] == -1 || grid[x2][y2] == -1)
            return INT_MIN;
        
        int lookup = (x1+1)*1000000 + (y1+1)*10000 + (x2+1)*100 + y2+1;
        if(umap.find(lookup) != umap.end())
        {
            return umap[lookup];
        }
        
        if(x1 == n-1 && y1 == n-1)
        {
            if(grid[x1][y1] != -1)
                return grid[x1][y1];
            else
                return INT_MIN;
        }
        
        int cherries = 0;
        if(x1 == x2 && y1 == y2)
            cherries += grid[x1][y1];
        else
            cherries += grid[x1][y1] + grid[x2][y2];
        
        vector<int> results;
        
        results.push_back(solve(x1+1, y1, x2+1, y2, grid, umap));
        results.push_back(solve(x1, y1+1, x2, y2+1, grid, umap));
        results.push_back(solve(x1+1, y1, x2, y2+1, grid, umap));
        results.push_back(solve(x1, y1+1, x2+1, y2, grid, umap));
        
        cherries += *max_element(results.begin(), results.end());
        umap.insert(make_pair(lookup, cherries));
        return cherries;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid)
    {
        unordered_map<int, int> umap;
        
        int res = solve(0, 0, 0, 0, grid, umap);
        return max(0, res);
    }
};