class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        vector <int> DP(nums.size(), 0);
        
        DP[0] = nums[0];
        DP[1] = std::max(nums[0],nums[1]);
        
        for(int i = 2; i<DP.size(); ++i)
        {
            DP[i] = std::max(nums[i] + DP[i-2], DP[i-1]);
        }
        
        return DP[DP.size()-1];
    }
};