#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
int dis[1005];

void bfs(int src, int n) 
{
    queue<int> q;
    q.push(src);
    dis[src] = 0;

    while(!q.empty()) 
    {
        int node = q.front();
        q.pop();

        for(int next : v[node]) 
        {
            if (dis[next] == -1) 
            {
                dis[next] = dis[node] + 1;
                q.push(next);
            }
        }
    }
}

int main() 
{
    int n, x;
    cin >> n >> x;

    int mat[n][n];

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            cin >> mat[i][j];
        }
    }

    vector<pair<int, int>> edgeList;

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            if(mat[i][j] == 1 && i != j) 
            {
                edgeList.push_back({i, j});
            }
        }
    }

    for(pair<int, int> edge : edgeList) 
    {
        int a = edge.first;
        int b = edge.second;
        v[a].push_back(b);
    }

    memset(dis, -1, sizeof(dis));
    bfs(x - 1, n);

    for(int i = 0; i < n; i++) 
    {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}
