#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int INF = 100;

int main()
{
    ll n;
    cin >> n;

    ll adj[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = INT_MAX;
            if(i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INF;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x != INF) 
            {
                adj[i][j] = x;
            }
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(adj[i][j] == INT_MAX)
                cout << INF;
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
