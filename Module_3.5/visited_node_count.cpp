#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> v[N];
bool vis[N];
int cnt = 0;

void dfs(int source)
{
    cnt++;
    //cout << source << endl;
    vis[source] = true;
    for(int child : v[source])
    {
        if(vis[child] == false)
        {
            dfs(child);
        }
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    
    int source;
    cin >> source;
    
    dfs(source);
    
    cout << "Visited Node - " << cnt << endl;
    
    return 0;
}