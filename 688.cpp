class Solution {
public:
    vector <pair<int, int>> dir = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    double dp[26][26][101];
    double knightProbability(int n, int k, int row, int column)
    {
        return helper(n, k, row, column);
    }
    
    double helper(int n, int k, int r, int c)
    {
        if(r < 0 || r > n-1 || c < 0 || c > n-1)
            return 0.0;
        if(k==0)
            return 1.0; 
        if(dp[r][c][k] != 0.0)
            return dp[r][c][k];
        
        double rate = 0.0;
        for(int i = 0; i < dir.size(); ++i)
        {
            rate += 0.125 * helper(n, k-1, r+dir[i].first, c+dir[i].second);
        }
        dp[r][c][k] = rate;
        return rate;
    }
};