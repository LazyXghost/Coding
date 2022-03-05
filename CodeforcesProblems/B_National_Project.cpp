#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, g, b;
        cin >> n >> g >> b;
        int gdreq = ceil(n / 2.0);
        long long pairs;
        long long res = 0;
        if ((ceil(gdreq / (double)g) - 1) * (long long)b <= n - gdreq)
            res += n;
        else
        {
            pairs = ceil((n - gdreq) / (double)b);
            gdreq -= pairs * g;
            res += pairs * (g + b);

            pairs = ceil(gdreq / (double)g) - 1;
            gdreq -= pairs * g;
            res += pairs * (g + b) + gdreq;
        }
        cout << res << "\n";
    }
    return 0;
}