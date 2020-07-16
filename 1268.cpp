class Solution {
public:
    void match(vector<string> &products, string key, int limit, vector<string> &allMatches){
        bool flag;
        for(int i = 0; i < products.size(); ++i)
        {
            flag = true;
            for(int j = 0; j<=limit; ++j)
            {   
                if(products[i][j]!=key[j])
                    flag = false;
            }
            if(flag)
                allMatches.push_back(products[i]);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        sort(products.begin(), products.end());
        
        vector<vector<string>> sugs;
        vector<string> allMatches;
        vector<string> temp;

        for(int i = 0; i<searchWord.size(); ++i)
        {
            allMatches.clear();
            match(products, searchWord, i, allMatches);
            temp.clear();
            if(allMatches.size()>=3)
            {
                sugs.push_back(vector<string>(allMatches.begin(), allMatches.begin()+3));
            }   
            else
                sugs.push_back(allMatches);
           
        }
        return sugs;
    }
};