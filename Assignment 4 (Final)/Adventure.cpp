#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll n, W;
        cin >> n >> W;
        
        ll weight[n], value[n];

        for(ll i=0; i<n; i++)
        {
            cin >> weight[i];
        }
        for(ll i=0; i<n; i++)
        {
            cin >> value[i];
        }

        ll dp[n+1][W+1];

        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=W; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0; 
                }
            }
        }

        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=W; j++)
            {
                if(weight[i-1] <= j)
                {
                    ll op1 = dp[i-1][j-weight[i-1]] + value[i-1];
                    ll op2 = dp[i-1][j];
                    dp[i][j] = max(op1, op2);
                }
                else
                {
                    ll op2 = dp[i-1][j];
                    dp[i][j] = op2;
                }
            }
        }

        cout << dp[n][W] << endl;
    }
    
    return 0;
}