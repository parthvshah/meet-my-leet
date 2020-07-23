class Solution {
public:
    int minFlips(int a, int b, int c) {
        string aS = bitset<128>(a).to_string();
        string bS = bitset<128>(b).to_string();
        string cS = bitset<128>(c).to_string();
        
        int change = 0;
        for(int i = 0; i<aS.size(); ++i)
        {
            if(cS[i]=='0' && aS[i]!='0' && bS[i]!='0')
            {
                change++;
                if(aS[i]=='1' && bS[i]=='1')
                    change++;
            }
            if(cS[i]=='0' && aS[i]=='1' && bS[i]=='0')
                change++;
            if(cS[i]=='0' && aS[i]=='0' && bS[i]=='1')
                change++;
            if(cS[i]=='1' && aS[i]=='0' && bS[i]=='0')
                change++;
        }
        return change;
    }
};