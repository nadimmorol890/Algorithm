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

        ll h[n];
        
        priority_queue<pair<ll, ll>> pq;
        
        for(ll i=0; i<n; i++)
        {
            cin >> h[i];
            pq.push({h[i], i});

        }

        pair<ll, ll> height1 = pq.top();
        pq.pop();
        pair<ll, ll> height2 = pq.top();
        pq.pop();

        if(height1.second < height2.second)
            cout << height1.second <<" "<< height2.second << endl;
        else
            cout << height2.second <<" "<< height1.second << endl;
    }
    
    return 0;
}