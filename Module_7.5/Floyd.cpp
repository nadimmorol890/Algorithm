#include<bits/stdc++.h>
#define ll long long int
using namespace std;
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
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int weight;
            cin >> weight;
            if (weight != -1) 
            {
                adj[i][j] = weight;
            }
        }
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    ll max_short_dis = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(adj[i][j] != INT_MAX && adj[i][j] > max_short_dis)
            {
                max_short_dis = adj[i][j];
            }
        }
    }

    cout << max_short_dis << endl;
    
    return 0;
}

