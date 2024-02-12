#include<bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
vector<int> v[N];
bool vis[N];
int level[N];
int parent[N];
 
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    
    vis[src] = true;
    level[src] = 0;
    
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
    
        for(int child : v[par])
        {
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par]+1;
                parent[child] = par;
            }
        }
    }
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int src = 1;
    int des = n;
 
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    
    bfs(src);
 
    if(level[des] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else 
    {
        cout << level[des] + 1 << endl;
        
        vector<int> path;
        
        int x = des;
        while(x != -1)
        {
            path.push_back(x);
            x = parent[x];
        }
        
        reverse(path.begin(), path.end());
        
        for(int val : path)
        {
            cout << val << " ";
        }
    }
    return 0;
}