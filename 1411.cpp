#define l long int
class Solution {
public:
    int numOfWays(int n) {
        l t = 6;
        l d = 6;
        
        for(int i = 2; i<=n; ++i)
        {
            l tt = t;
            t = (2*t + 2*d)%((l)(1e9+7));
            d = (2*tt + 3*d)%((l)(1e9+7));
        }
            
        return(t+d)%((l)(1e9+7));
    }
};