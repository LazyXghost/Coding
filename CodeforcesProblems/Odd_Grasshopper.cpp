#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, n;
        cin >> x >> n;
        int rem = n%4;
        for (long long i = n - rem + 1; i <= n; i++)
        {
            if (x % 2 == 0)
                x -= i;
            else
                x += i;
        }
        cout<<x<<"\n";
    }

    return 0;
}