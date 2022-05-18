// f(i+1) = f(i) + sum(Array) -  last element * array.length

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int s = nums.size();
        int numSum = 0;
        vector <int> DP(s);
        
        for(int i = 0; i<s; ++i)
        {
            DP[0] += i*nums[i];
            numSum += nums[i];
        }
        
        for(int j = 1; j<s; ++j)
        {
            DP[j] = DP[j-1] + numSum - (nums[s-j]*s);
        }
        
        return *max_element(DP.begin(), DP.end());
        
    }
};