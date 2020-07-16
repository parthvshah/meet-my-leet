#define pb push_back
class Solution {
public:
    int res;
    
    void dfs(int v, vector<vector<int> >& adj, vector<bool>& visited)
    {

        visited[v]=true;
        
        for(int i = 0; i<adj[v].size(); ++i)
        {            
            if(!visited[abs(adj[v][i])])
            {
                if(adj[v][i]>0)
                    res++;
                dfs(abs(adj[v][i]), adj, visited);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int> > adj(n);
        res = 0;
        for(int i=0; i<connections.size(); ++i)
        {
            adj[connections[i][0]].pb(connections[i][1]);
            adj[connections[i][1]].pb(-1*connections[i][0]);
        }
        
        vector<bool> visited(n, false);
        dfs(0, adj, visited);
        
        return (res);
    }
};