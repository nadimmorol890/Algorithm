#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+5;
ll parent[N+1];
ll group_size[N+1];

void dsu_initialize(ll n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(ll node)
{
    if(parent[node] == -1) return node;
    
    ll leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union_by_size(ll node1, ll node2)
{
    ll leaderA = dsu_find(node1);
    ll leaderB = dsu_find(node2);

    if(group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

class Edge
{
    public:
    ll u, v ,w;
    Edge(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    ll n, e;
    cin >> n >> e;
    
    dsu_initialize(n);
    
    vector<Edge> edgeList;
    vector<pair<ll, ll>> dltRoad;
    
    while(e--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }
    
    sort(edgeList.begin(), edgeList.end(), cmp);

    ll totalCost = 0;
    ll connectedBuilding = 1;
    
    for(Edge ed : edgeList)
    {
        ll leaderU = dsu_find(ed.u);
        ll leaderV = dsu_find(ed.v);

        if(leaderU == leaderV)
        {
            dltRoad.push_back({ed.u,ed.v});
            continue;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.w;
            connectedBuilding++;
        }
    }

    if(connectedBuilding < n)
    {
        cout << "Not Possible" << endl;
    }
    else
    {
        cout << dltRoad.size() << " " << totalCost << endl;
    }

    return 0;
}
