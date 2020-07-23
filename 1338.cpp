class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> c;
        for(int i = 0; i<arr.size(); ++i)
        {
            if(c.count(arr[i])==0)
                c.insert({arr[i], 1});
            else
                c[arr[i]]+=1;
        }
        vector<int> delArr;
        for(auto elem:c)
        {
            delArr.push_back(elem.second);
        }
        sort(delArr.begin(), delArr.end(), greater<int>());
        
        int n = arr.size();
        int delSum = 0;
        int res = 0;
        int k = 0;
        while(delSum<(n/2))
        {
            delSum+=delArr[k++];
            res++;
        }
        return res;
    }
};