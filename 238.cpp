class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> rprod(n);
        vector<int> lprod(n);
        
        rprod[0] = nums[0];
        for(int i = 1; i<n; ++i)
        {
            rprod[i] = rprod[i-1]*nums[i];
        }
        
        lprod[n-1] = nums[n-1];
        for(int j = n-2; j>=0; j--)
        {
            lprod[j] = lprod[j+1]*nums[j];
        }
        
        // for(int k = 0; k<lprod.size(); ++k)
        //     cout << lprod[k] << " ";
        // cout << endl;
        
        // for(int k = 0; k<rprod.size(); ++k)
        //     cout << rprod[k] << " ";
        // cout << endl;
        
        vector<int> res(n);
        
        res[0] = lprod[1];
        for(int k = 1; k<n-1; ++k)
        {
            res[k] = rprod[k-1]*lprod[k+1];
        }
        res[n-1] = rprod[n-2];
        
        return res;
    }
};