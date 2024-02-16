#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
char a[N][N];
bool vis[N][N];
vector<pair<int,int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};

int n,m;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '-');
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;

    int area = 1;

    for(int i=0; i<4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && !vis[ci][cj])
        {
            area += dfs(ci,cj);
        }
    }
    return area;
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
            vis[i][j] = false;
        }
    }

    int minArea = -1;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j] == '.' && !vis[i][j])
            {
                int area = dfs(i, j);

                if(minArea == -1 || area < minArea)
                {
                    minArea = area;
                }
            }
        }
    }

    cout << minArea << endl;

    return 0;
}