#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n == 0) return 1;    //base case
    int chotoFactorial = fact(n-1);
    return n * chotoFactorial;
}
int main()
{
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}