class Solution {
public:
    int calc(string s, string l)
    {
        for(int i = 0; i < l.size(); ++i)
        {
            string tmp = l;
            l.erase(l.begin()+i);
            if(l.compare(s) == 0)
                return 1;
            l = tmp;
        }
        return 0;
    }
    int longestStrChain(vector<string>& words)
    {
        sort(words.begin(), words.end(), []
            (const string& first, const string& second)
            {
                return first.size() > second.size();
            });
        
        vector<int> res;
        for(int i = 0; i<words.size()-1; ++i)
        {
            res.push_back(calc(words[i], words[i+1]));
            cout << res[i] << " ";
        }
        return 0;
    }
};