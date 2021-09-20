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
#define input(x) cin >> x
#define space cout << " "
#define newline cout << "\n"

const ll MOD = 1e9 + 7;

bool isPrime(int n)
{
    if (n == 2 || n == 3)
    {
        return true;
    }
    else if (n == 1 || n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FASTIO;
    int n;
    cin >> n;
    long long arr[n];
    forloop(i, 0, n)
    {
        input(arr[i]);
    }
    forloop(i, 0, n)
    {
        double temp = sqrt(arr[i]);
        int tempmodulo = temp;
        if (temp != tempmodulo)
        {
            print("NO");
            newline;
        }
        else
        {
            if (isPrime(tempmodulo))
            {
                print("YES");
                newline;
            }
            else
            {
                print("NO");
                newline;
            }
        }
    }

    return 0;
}