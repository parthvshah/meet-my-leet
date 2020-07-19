class Solution {
public:
    int lps(string s, int i, int j, vector<vector<int>> &dp)
    {
        if(dp[i][j])
            return dp[i][j];
        
        if(i == j)
        {
            dp[i][j]=1;
            return 1;
        }
        else if(s[i]==s[j] && i+1==j)
        {
            dp[i][j]=2;
            return 2;
        }
        else if(s[i]==s[j])
        {
            dp[i][j] = lps(s, i+1, j-1, dp) + 2;
            return dp[i][j];
        }
        
        dp[i][j] = max(lps(s, i+1, j, dp), lps(s, i, j-1, dp));
        return dp[i][j];
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        return(n-lps(s, 0, n-1, dp));
    }
};