class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        
        int ans = 1, last = pairs[0][1];
        
        for(int i = 1; i<pairs.size(); ++i)
        {
            if(last<pairs[i][0])
            {
                last = pairs[i][1];
                ans++;
            }
            if(last>pairs[i][1])
            {
                last = pairs[i][1];
            }
                
        }
        
        return ans;
    }
};