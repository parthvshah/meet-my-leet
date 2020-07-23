class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        int count = 0;
        double res;
        bool isOrdered;
        sort(A.begin(), A.end());
        
        do
        {
            isOrdered = true;
            for(int i = 0; i<A.size()-1; ++i)
            {
                res = sqrt(A[i]+A[i+1]);
                
                if(res-((int)res)!=0)
                {
                    isOrdered = false;
                    break;
                }
                    
            }
            if(isOrdered)
                count++;
            
        } while (next_permutation(A.begin(), A.end()));
        
        return count;
    }
};