#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool is_achieve_Mark(ll arr[], ll sum, ll N)
{
    bool dp[N+1][sum+1];
    
    dp[0][0] = true;
        
    for(int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= sum; j++)
        {
            if(arr[i-1] <= j)
            {
                bool op1  = dp[i-1][j-arr[i-1]]; 
                bool op2  = dp[i-1][j];
    
                dp[i][j] = op1 || op2;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[N][sum];
}
int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        ll n, m;
        cin >> n >> m;

        ll arr[n];
        
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        ll sum = (1000 - m);
        
        if(is_achieve_Mark(arr, sum, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}