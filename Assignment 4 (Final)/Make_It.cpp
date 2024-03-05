#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canReach(ll n)
{
    bool dp[n+1];
    
    for(int i = 1; i <= n; i++)
    {
        dp[i] = false;
    }

    dp[1] = true;

    for(ll i = 1; i <= n; i++) 
    {
        if(dp[i] == true)
        {
            if (i + 3 <= n) dp[i + 3] = true;
            if (i * 2 <= n) dp[i * 2] = true;
        }
    }

    return dp[n];
}

int main()
{
    ll t;
    cin >> t;
    
    while(t--)
    {
        ll n;
        cin >> n;

        if(canReach(n) == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}