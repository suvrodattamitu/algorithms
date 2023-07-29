vector<int> e;
int dis[100005];
int vis[100005];
int ans=-1;

void dfs(int u,int d,int t)
{
    if(dis[u]!=-1)
    {
        if(vis[u]==t)
        ans=max(ans,d-dis[u]);
        return;
    }
    vis[u]=t;
    dis[u]=d;
    if(e[u]>=0)
    dfs(e[u],d+1,t);
}

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        ans=-1;
        memset(dis,-1,sizeof(dis));
        e=edges;
        for(int i=0;i<edges.size();i++)
        {
            if(dis[i]==-1)
            {
                dfs(i,0,i);
            }
        }
        return ans;
    }
};