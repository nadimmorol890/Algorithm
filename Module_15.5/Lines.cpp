#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
bool is_valid(int n, int m, int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= m)
        return false;
    else
        return true;
}
void bfs(int n, int m, vector<vector<char>> &maze, int row, int col, vector<vector<pair<int, int>>> &parent_arr)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({row, col});
    visited[row][col] = true;
    parent_arr[row][col] = {-1, -1};
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        for (int i = 0; i < d.size(); i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (is_valid(n, m, ci, cj) && !visited[ci][cj] && maze[ci][cj] != 'O')
            {
                q.push({ci, cj});
                parent_arr[ci][cj] = par;
                visited[ci][cj] = true;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int sr, sc, dr, dc;
    vector<vector<char>> maze(n, vector<char>(n));
    vector<vector<pair<int, int>>> parent_arr(n, vector<pair<int, int>>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            parent_arr[i][j] = {-1, -1};
            cin >> maze[i][j];
            if (maze[i][j] == '@')
            {
                sr = i;
                sc = j;
            }
            if (maze[i][j] == 'X')
            {
                dr = i;
                dc = j;
            }
        }
    }
    bfs(n, n, maze, sr, sc, parent_arr);
    if (parent_arr[dr][dc].first != -1 && parent_arr[dr][dc].second != -1)
    {
        cout << "Y" << endl;

        while (dr != -1 && dc != -1)
        {
            maze[dr][dc] = '+';
            pair<int, int> p = parent_arr[dr][dc];
            dr = p.first;
            dc = p.second;
        }
        maze[sr][sc] = '@';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << maze[i][j];
            }
            cout << endl;
        }
    }
    else
        cout << "N" << endl;
        
    return 0;
}