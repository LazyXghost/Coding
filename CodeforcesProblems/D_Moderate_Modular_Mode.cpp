#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

long long findres(int x, int y)
{
    for (int i = 2; i <= x; i++)
        if (i % x == y % i)
            return i;
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        long long res;
        if (x > y)
            res = x + y;
        else
            res = y - (y%x)/2;
        cout << res << "\n";
    }
    return 0;
}