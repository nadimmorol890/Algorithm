#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;

    vector<int> mat[n+1];

    while(e--)
    {
        int a,b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;

        if(x >= 0 && x < n && !mat[x].empty())
        {
            sort(mat[x].begin(), mat[x].end(), greater<int>());

            for(int ans:mat[x])
            {
                cout << ans <<" ";
            }
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}