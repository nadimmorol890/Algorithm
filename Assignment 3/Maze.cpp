#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
char a[N][N];
bool vis[N][N];
map<pair<int, int>, pair<int, int>> parent;

int dx[4] ={0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return (!vis[x][y] && a[x][y] != '#' && x >= 0 && x < n && y >= 0 && y < m);
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);

    vis[src.first][src.second] = true;

    while(!q.empty())
    {
        auto par = q.front();
        q.pop();
        int x = par.first;
        int y = par.second;

        for(int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if(valid(new_x, new_y))
            {
                q.push({new_x, new_y});
                vis[new_x][new_y] = true;
                parent[{new_x, new_y}] = {x, y};
            }
        }
    }
}

int main()
{
    
    pair<int, int> src, des;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            
            if(a[i][j] == 'R')
                src = {i, j};
            
            if(a[i][j] == 'D')
                des = {i, j};
        }
    }

    bfs(src);

    if(vis[des.first][des.second] == false)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    else
    {

        pair<int, int> cur = des;
        
        while (cur != src) 
        {
            a[cur.first][cur.second] = 'X';
            cur = parent[cur];
        }
        
        a[des.first][des.second] = 'D';
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}