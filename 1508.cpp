class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        priority_queue<int> sums;
        int inter;
        
        sums.push(-1*nums[nums.size()-1]);
        for(int i=0; i<nums.size()-1; ++i)
        {
            sums.push(-1*nums[i]);
            for(int j=i+1; j<nums.size(); ++j)
            {
                inter = 0;
                for(int k=i; k<=j; ++k)
                {
                    inter += nums[k];
                }
                sums.push(-1*inter);
            }
        }
        
        int result = 0;
        int diff = right-left+1;
        left--;
        while(left--)
            sums.pop();
        
        while(diff--)
        {
            result+=sums.top();
            sums.pop();
        }
        
        result *= -1;
        return result%(1000000007);
    }
};