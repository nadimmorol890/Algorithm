#include<bits/stdc++.h>
using namespace std;

const int N = 105;

bool vis[N][N];
int dis[N][N];
vector<pair<int,int>> d = {{-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}};

int n,m;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while(!q.empty())
    {
        pair<int,int> par = q.front();
        int a = par.first;
        int b = par.second;
        q.pop();
        
        for(int i=0; i<8; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if(valid(ci,cj) == true && vis[ci][cj] == false)
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
    
        int ki,kj;
        cin >> ki >> kj;
        int qi,qj;
        cin >> qi >> qj;

        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        
        bfs(ki, kj);
        
        if(dis[qi][qj] != -1)
            cout << dis[qi][qj] << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}