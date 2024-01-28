#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int a[N][N];
bool vis[N][N];

int dx[4] ={0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return !vis[x][y] && a[x][y] != -1 && x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);

    vis[src.first][src.second] = true;

    while(!q.empty())
    {
        auto parent = q.front();
        q.pop();
        int x = parent.first;
        int y = parent.second;

        for(int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(valid(new_x, new_y))
            {
                q.push({new_x, new_y});
                vis[new_x][new_y] = true;
            }
        }
    }
}

int count_apartment()
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j =0; j < m; j++)
        {
            if(vis[i][j] == false && a[i][j] != -1)
            {
                bfs({i, j});
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
                a[i][j] = -1;
        }
    }
    
    int ans = count_apartment();
    cout << ans << endl;
    
    return 0;
}