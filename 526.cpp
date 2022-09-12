class Solution {
public:
    int helper(vector<int> input, int n)
    {
        if(n <= 0)
            return 1;
        
        int ans = 0;
        for(int i = 0; i<n; ++i)
        {
            if(input[i] % n == 0 || n % input[i] == 0)
            {
                swap(input[i], input[n-1]);
                ans += helper(input, n-1);
                swap(input[i], input[n-1]);
            }
        }
        return ans;
    }
    
    int countArrangement(int n)
    {
        vector<int> input;
        for(int i = 1; i <= n; ++i)
        {
            input.push_back(i);
        }
        
        return helper(input, n);
    }
};