#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
char a[N][N];
bool vis[N][N];
int dis[N][N];
vector<pair<int,int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};

int n,m;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '-');
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
        
        for(int i=0; i<4; i++)
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
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    int si,sj;
    cin >> si >> sj;
    int di,dj;
    cin >> di >> dj;

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    
    bfs(si, sj);
    
    if(dis[di][dj] != -1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}