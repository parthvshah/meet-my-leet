#define ll long long int
#define MOD 1000000007
class Solution {
public:
    ll countVowelPermutation(ll n) {
        vector<vector<ll> > DP(5, vector<ll>(n+1, 0));
        
        // 0 - a, 1 - e, 2 - i, 3 - o, 4 - u
        DP[0][1]=1; DP[1][1]=1; DP[2][1]=1; DP[3][1]=1; DP[4][1]=1;
        if(n==1)
            return 5;
        
        DP[0][2]=1; DP[1][2]=2; DP[2][2]=4; DP[3][2]=2; DP[4][2]=1;
        if(n==2)
            return 10;
        
        for(ll i = 3; i<=n; ++i)
        {
            
            DP[0][i]=0.5 * DP[1][i-1] + 0.25 * DP[2][i-1] + DP[4][i-1];
            DP[1][i]=2 * (DP[0][i-1] + 0.25 * DP[2][i-1]);
            DP[2][i]=4 * (0.5 * DP[1][i-1] + 0.5 * DP[3][i-1]); 
            DP[3][i]=2 * (0.25 * DP[2][i-1]); 
            DP[4][i]=0.25*DP[2][i-1] + 0.5*DP[3][i-1];
        }
        
        return ((ll)(DP[0][n]+DP[1][n]+DP[2][n]+DP[3][n]+DP[4][n]))%MOD;
        
    }
};