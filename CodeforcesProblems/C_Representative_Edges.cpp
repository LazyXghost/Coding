#include <bits/stdc++.h>
using namespace std;

// typedef is used to give datatype a newname
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// define is used to give things an alias
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fill(start, end, val) fill(start, end, val)

#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define loopreverse(i, a, b) for (int i = a; i >= b; i--)
#define iteratorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define iteratorloopreverse(v, i) for (auto i = v.end() - 1; i != v.begin() - 1; i--)
#define printArray(arr, n, i)   \
    for (int i = 0; i < n; i++) \
    {                           \
        print(arr[i]);          \
        space;                  \
    }                           \
    newline;
#define inputArray(arr, n, i)   \
    for (int i = 0; i < n; i++) \
    {                           \
        input(arr[i])           \
    }
#define printVector(v, i)                       \
    for (auto i = v.begin(); i != v.end(); i++) \
    {                                           \
        print(val(i));                          \
        space;                                  \
    }                                           \
    newline;
#define inputVector(v, n, i)    \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        input(x);               \
        v.push_back(x);         \
    }
#define val(x) (*(x))

#define print(x) cout << x;
#define input(x) cin >> x;
#define space cout << " ";
#define newline cout << "\n";

const ll MOD = 1e9 + 7;

bool comparator(pii a, pii b)
{
    return (a.first < b.first);
}

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})
// vector<int> v({SIZE OF VECTOR})

int findAnswer(int a[], int n)
{
    if (n == 1)
    {
        return 0;
    }

    int res = INT_MAX, start, muldiff;
    for (double gap = 1; gap <= n - 1; gap++)
    {
        // print("Gap is " << gap);
        // newline;
        loop(i, 0, n - gap - 1)
        {
            int tempres = 0;
            start = a[i];
            muldiff = a[i + (int)gap] - a[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j] != start - (((i - j) * muldiff) / gap))
                {
                    tempres++;
                }
            }
            for (int j = i + 1; j <= n - 1; j++)
            {
                if (a[j] != start + (((j - i) * muldiff) / gap))
                {
                    tempres++;
                }
            }
            res = min(res, tempres);
            // print("res became " << res << " for a[i] = " << a[i]);
            // newline;
        }
    }
    return res;
}

int main()
{
    FASTIO;
    tests(t)
    {
        int n;
        input(n);
        int a[n];
        inputArray(a, n, i);
        print(findAnswer(a, n));
        newline;
    }
    return 0;
}