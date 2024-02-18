#include<bits/stdc++.h>
using namespace std;

// Complexity O(2^N)
int fibo(int n)
{
    if(n == 0 || n == 1) return n;  //base case

    int ans = fibo(n-1) + fibo(n-2);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}