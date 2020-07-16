#define pb push_back
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> B(A);
        sort(B.begin(), B.end());
        
        vector<int> res;
        int currentPos;
        for(int i = B.size()-1; i>=0; i--)
        {
            currentPos = 0;
            if(B[i]==A[i])
                continue;
            
            for(int j = 0; j<A.size(); ++j)
                if(A[j]==B[i])
                    currentPos = j;
            
            res.pb(currentPos+1);
            reverse(A.begin(), A.begin() + currentPos + 1);
            
            res.pb(i+1);
            reverse(A.begin(), A.begin() + i + 1);
        }
        return res;
    }
};