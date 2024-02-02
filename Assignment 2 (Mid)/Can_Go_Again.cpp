#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Edge
{
    public:
        ll u, v, c;
        Edge(ll u,ll v,ll c)
        {
            this->u = u;
            this->v = v;
            this->c = c;
        }
};

const ll INF = 1e18+5;
ll dis[1001];

int main()
{
    ll n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while(e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        EdgeList.push_back(Edge(a,b,w));
    }

    for(int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    ll s;
    cin >> s;
    dis[s] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(Edge ed : EdgeList)
        {
            ll u,v,c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if(dis[u] < INF && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    
    for(Edge ed : EdgeList)
    {
        ll u,v,c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if(dis[u] < INF && dis[u] + c < dis[v])
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }

    ll t;
    cin >> t;
    while(t--)
    {
        ll d;
        cin >> d;

        if(dis[d] == INF)
        {
            cout << "Not Possible" << endl;
        } 
        else 
        {
            cout << dis[d] << endl;
        }
    }  
    
    return 0;
}