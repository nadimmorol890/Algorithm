#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll INF = 1e18+5;
int main()
{
    ll n, e;
    cin >> n >> e;

    ll adj[n+1][n+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            adj[i][j] = INF;
            if(i == j)
                adj[i][j] = 0;
        }
    }

    while(e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = min(adj[a][b], w);
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        ll x, y;
        cin >> x >> y;

        if(adj[x][y] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj[x][y] << endl;
        }
    }
    
    return 0;
}