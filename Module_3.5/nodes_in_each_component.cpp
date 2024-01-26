#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> v[N];
bool vis[N];

int dfs(int source)
{
    vis[source] = true;
    int sz = 1;
    for(int child : v[source])
    {
        if(vis[child] == false)
        {
            sz += dfs(child);
        }
    }
    return sz;
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
    vector<int> cmp_sz;
    
    for(int i=0; i<n; i++)
    {
        if(vis[i] == false)
        {
            int size = dfs(i);
            cmp_sz.push_back(size);
        }
    }
    
    sort(cmp_sz.begin(),cmp_sz.end());

    for(int ans : cmp_sz)
    {
        cout << ans << " ";
    }
    cout << endl;
    
    return 0;
}