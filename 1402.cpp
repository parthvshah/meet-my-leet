class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        if(satisfaction[n-1]<=0) 
            return 0;
        
        int res = satisfaction[n-1];
        
        for(int i = n-2; i >= 0; i--)
        {
            satisfaction[i]+=satisfaction[i+1];
            if(satisfaction[i]>=0)
                res+=satisfaction[i];
            else
                break;
        }
        return res;
    }
};