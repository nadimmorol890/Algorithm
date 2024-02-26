#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool count_diff(ll arr[], ll n, ll s)
{
    if (n == 1)
    {
        if (s == 0)
            return true;
        else
            return false;
    }
    if (arr[n - 1] <= s)
    {
        bool op1 = count_diff(arr, n - 1, s - arr[n - 1]);
        bool op2 = count_diff(arr, n - 1, s);
        return op1 || op2;
    }
    else
    {
        return count_diff(arr, n - 1, s);
    }
}

int main()
{
    int n;
    cin >> n;

    ll arr[n];
    
    ll diff;
    cin >> diff;
    
    ll sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    
    ll s = (sum + diff) / 2;

    bool flag = count_diff(arr, n, s-arr[0]);
    
    if(flag && (sum + diff) % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}