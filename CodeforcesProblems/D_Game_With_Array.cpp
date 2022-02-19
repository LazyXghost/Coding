#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
    FASTIO;
    int n,s;
    cin >> n >> s;

    if (s < 2 * n)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        int tmp = n - 1;
        while (tmp--)
            cout << 1 << " ";
        cout << s - n + 1 << "\n"
             << n << "\n";
    }
    return 0;
}
