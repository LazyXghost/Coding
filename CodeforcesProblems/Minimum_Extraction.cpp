#include <bits/stdc++.h>
using namespace std;

// typedef is used to give datatype a newname
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// define is used to give things an alias
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fill(start, end, val) fill(start, end, val)

#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define forloop(i, a, b) for (int i = a; i < b; i++)
#define forloopreverse(i, a, b) for (int i = a; i > b; i--)
#define vectorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define vectorloopreverse(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define val(x) (*(x))

#define print(x) cout << x
#define space cout << " "
#define newline cout << "\n"

const ll MOD = 1e9 + 7;

int main()
{
    FASTIO;
    tests(t)
    {
        int n;
        cin >> n;
        vi v;
        forloop(i, 0, n)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        if (n == 1)
        {
            print(val(v.begin()));
            newline;
        }
        else
        {
            sort(v.begin(), v.end());
            int res = val(v.begin());
            vectorloop(v, i)
            {
                if (i != v.begin())
                    res = max(res, val(i) - val(i - 1));
            }
            print(res);
            newline;
        }
    }
    return 0;
}