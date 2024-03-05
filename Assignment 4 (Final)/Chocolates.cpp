#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;
        
        ll a[n];
        ll s = 0;
        
        for(ll i=0; i<n; i++)
        {
            cin >> a[i];
            s += a[i];
        }

        if(s%2 == 0)
        {
            ll sum = s/2;
            
            bool dp[n+1][sum+1];
            
            dp[0][0] = true;
            
            for(ll i = 1; i <= sum; i++)
            {
                dp[0][i] = false;
            }

            for(ll i = 1; i <= n; i++)
            {
                for(ll j = 0; j <= sum; j++)
                {
                    if(a[i-1] <= j)
                    {
                        bool op1 = dp[i-1][j - a[i-1]];
                        bool op2 = dp[i-1][j];

                        dp[i][j] = op1 || op2;
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }

            if(dp[n][sum])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}