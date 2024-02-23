#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+5;
ll a[N];
ll dp[N];
ll n;

ll Solution(ll n) 
{
    if(n < 1) return 0;
    if(dp[n] != -1) return dp[n];

    ll op1 = Solution(n-1);
    ll op2 = Solution(n-2) + a[n-1];

    return dp[n] = max(op1,op2);
}
int main()
{
    ll t;
    cin >> t;
    
    ll cs = 1;

    while(t--)
    {
        cin >> n;
        
        for(ll i=0; i<n; i++)
        {
            cin >> a[i];
        }
        
        memset(dp, -1, sizeof(dp));
        
        cout <<"Case "<< cs++ <<": "<< Solution(n) << endl;
    }

    return 0;
}