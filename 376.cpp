class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        vector <int> up(n, 0);        
        vector <int> dw(n, 0);
        
        up[0] = 1;      
        dw[0] = 1;
        
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] > nums[i-1])
            {
                up[i] = dw[i-1] + 1;
                dw[i] = dw[i-1];
            }
            else if(nums[i] < nums[i-1])
            {
                dw[i] = up[i-1] + 1;
                up[i] = up[i-1];
            }
            else
            {
                up[i] = up[i-1];
                dw[i] = dw[i-1];
            }

        }
        
        return std::max(up[n-1], dw[n-1]);
    }
};