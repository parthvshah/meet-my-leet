class Solution {
public:
    void DFS(int v, vector<bool>& visited, vector<vector<int>>& M){
        visited[v] = true;
        for(auto i = M[v].begin(); i < M[v].end(); ++i)
        {
            if(!visited[*i])
            {
                DFS(*i, visited, M);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        int n = M.size();
        vector<bool> visited(n, false);
        
        vector<vector <int> > adj(n, vector<int>(n));
        
        for(int i = 0; i<M.size(); ++i)
            for(int j = 0; j<M[i].size(); ++j)
            {
                if(M[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        
        for(int i = 0; i<n; ++i)
        {
            if(!visited[i])
            {
                DFS(i, visited, adj);
                count++;
            }
        }
        
        return count;
    }
};