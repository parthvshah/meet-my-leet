class Solution {
public:
    int mm(vector<int>& dims, int i, int j, vector<vector<int> >& DP){
        
        if(DP[i][j]!=-1)
            return DP[i][j];
        
        int _max = INT_MIN;
        int count = 0;
        
        
        if(i==j)
        {
            DP[i][j] = 0;
            return DP[i][j];
        }
            
        
        for(int k = i; k<j; ++k)
        {
            count = mm(dims, i, k, DP) + mm(dims, k+1, j, DP) + dims[i-1]*dims[k]*dims[j];
                
            if(count>_max)
                _max=count;
        }
        DP[i][j] = _max;
        return DP[i][j];
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector <int> > DP(nums.size()+1, vector<int>(nums.size()+1, -1));
        // for(int i = 0; i<nums.size()+1; ++i)
        //     DP[i][i] = 0;
        
        return mm(nums, 1, nums.size()-1, DP);
    }
};