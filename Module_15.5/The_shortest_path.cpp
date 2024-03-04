#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 500000+5;

vector<ll> v[N];
bool vis[N];
ll level[N];
ll parent[N];

void bfs(ll source)
{
    queue<ll> q;
    q.push(source);
    vis[source] = true;
    level[source] = 0;
    while(!q.empty())
    {
        ll par = q.front();
        q.pop();
    
        for(ll child : v[par])
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
    ll n,e;
    cin >> n >> e;

    ll source, des;
    cin >> source >> des;

    while(e--)
    {
        ll a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    
    bfs(source);

    ll x = des;
    
    vector<ll> path;
    while(x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    
    if(path.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        reverse(path.begin(),path.end());

        cout << path.size() - 1 << endl;
        
        for(ll val : path)
        {
            cout << val << " ";
        }
    }

    return 0;
}