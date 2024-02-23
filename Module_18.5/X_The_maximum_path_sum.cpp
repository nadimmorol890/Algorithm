#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxN = 15;
const ll maxM = 15;
ll a[maxN][maxM];
ll dp[maxN][maxM];
ll n,m;

ll find_MaxPath_Sum(ll i, ll j)
{
    if(i == n && j == m) return a[i][j];
    
    if(i > n || j > m) return INT_MIN;
    
    if(dp[i][j] != INT_MIN) return dp[i][j];

    ll downSum = find_MaxPath_Sum(i+1, j);
    ll rightSum = find_MaxPath_Sum(i, j+1);

    ll ans = a[i][j] + max(rightSum, downSum);
    
    return ans;
}

int main()
{
    cin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> a[i][j];
            dp[i][j] = INT_MIN;
        }
    }

    ll maxSum = find_MaxPath_Sum(1, 1);

    cout << maxSum << endl;

    return 0;
}
