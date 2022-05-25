class Solution {
public:
    long long countVowels(string word) {
        long long res = 0;
        for(int i = 0; i<word.length(); ++i)
        {
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
            {
                res += (i+1)*(word.length()-i);
            }
        }
        return res;
    }
};