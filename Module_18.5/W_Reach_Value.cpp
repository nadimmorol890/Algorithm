#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool recursion(ll x, ll n)
{
   if(x == n)
   {
        return true;
   }
   if(x > n)
   {
        return false;
   }

   return recursion(x * 10, n) || recursion(x * 20, n);
}

int main()
{
    ll t;
    cin >> t;
    
    while(t--)
    {
        ll n;
        cin >> n;

        if(recursion(1, n) == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}