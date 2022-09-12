class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        
        string ans;
        
        if (numerator > 0 ^ denominator > 0)
            ans += '-';
        
        long long n = labs(numerator);
        long long d = labs(denominator);
        long long r = n % d;
        
        ans += to_string(n/d);
        
        if (r == 0)
            return ans;
        
        ans += '.';
        
        unordered_map<long long, int> umap;
        
        while (r)
        {
            if (umap.find(r) != umap.end())
            {
                ans.insert(umap[r], "(");
                ans += ')';
                break;
            }
            umap[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        return ans;
    }
};