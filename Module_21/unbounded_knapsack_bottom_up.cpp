#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;

    int dp[n+1][W+1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
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

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            if(weight[i-1] <= j)
            {
                int ch1 = dp[i][j-weight[i-1]] + val[i-1];
                int ch2 = dp[i-1][j];

                dp[i][j] = max(ch1, ch2);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i=0; i<=n; i++)
    // {
    //     for(int j=0; j<=W; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][W] << endl;

    return 0;
}