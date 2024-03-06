#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int unbounded_knapsack(int n, int W, int val[], int weight[])
{
    if( n == 0 || W == 0) return 0;

    if(dp[n][W] != -1) return dp[n][W];

    if(weight[n-1] <= W)
    {
        int ch1 = unbounded_knapsack(n, W - weight[n-1], val, weight) + val[n-1];
        int ch2 = unbounded_knapsack(n-1, W, val, weight);

        return dp[n][W] = max(ch1, ch2);
    }
    else
    {
        return dp[n][W] = unbounded_knapsack(n-1, W, val, weight);
    }
}

int main()
{
    int n, W;
    cin >> n >> W;

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }

    int val[n], weight[n];

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cout << unbounded_knapsack(n, W, val, weight) << endl;

    return 0;
}