#define pb push_back
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> groups;
        
        vector<vector<int>> res;
        
        for(int i = 0; i<groupSizes.size(); ++i)
        {
            if(groups[groupSizes[i]].size()>=0)
            {
                groups[groupSizes[i]].pb(i);
            }
            else
            {
                groups.insert(pair<int, vector<int>>(groupSizes[i], vector<int>({})));
            }
        }
        
        vector<int> temp;
        for (auto elem : groups)
        {
            temp.clear();
            for(int j = 0; j<elem.second.size(); ++j)
            {
                temp.pb(elem.second[j]);
                if((j+1)%elem.first==0)
                {
                    res.pb(temp);
                    temp.clear();
                }
            }
            if(temp.size()!=0)
                res.pb(temp);
        }
        
        return res;
    }
};