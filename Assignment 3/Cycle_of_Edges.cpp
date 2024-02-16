#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool vis[N+1];
vector<int> adj[N+1];
int parentArray[N+1];
int cnt = 0;

void dfs(int parent)
{
    vis[parent] = true;

    for(int child : adj[parent])
    {
        if(vis[child] && child != parentArray[parent])
        {
            cnt++;
        }
        if(!vis[child])
        {
            parentArray[child] = parent;
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    
    cnt = 0;
    
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    cout << cnt/2 << endl;
    
    return 0;
}