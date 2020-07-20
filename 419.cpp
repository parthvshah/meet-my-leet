class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        
        for(int i = 0; i<board.size(); ++i)
        {
            for(int j = 0; j<board[i].size(); ++j)
            {
               if(board[i][j]=='X')
               {
                   if(j-1<0 && i-1<0)
                   {
                       count++;
                       continue;
                   }
                   if((j-1<0 && i-1>=0 && board[i-1][j]=='.') || (j-1>=0 && i-1<0 && board[i][j-1]=='.'))
                   {
                       count++;
                       continue;
                   }
                   if(i-1>=0 && board[i-1][j]=='.' && j-1>=0 && board[i][j-1]=='.')
                   {
                       count++;
                       continue;
                   }
               }
                  
            }
        }
        
        return count;
    }
};