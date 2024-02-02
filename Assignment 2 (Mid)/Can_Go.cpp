#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e5+5;
vector<pair<ll,ll>> v[N];
ll dis[N];

class cmp
{
    public:
        bool operator()(pair<ll,ll> a, pair<ll,ll> b)
        {
            return a.second > b.second;
        }
};

void dijkstra(ll src, ll n)
{
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while(!pq.empty())
    {
        pair<ll,ll> parent = pq.top();
        pq.pop();
        
        ll node = parent.first;
        ll cost = parent.second;
        
        for(pair<ll,ll> child : v[node])
        {
            ll childNode = child.first;
            ll childCost = child.second;
            
            if(cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;
    while(e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b,w});
    }

    ll s,t;
    cin >> s;
    cin >> t;
    while(t--)
    {
        ll d, dw;
        cin >> d >> dw;

        for(int i = 1; i <= n; i++)
        {
            dis[i] = INT_MAX;
        }

        dijkstra(s, n);

        if(dis[d] <= dw)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}