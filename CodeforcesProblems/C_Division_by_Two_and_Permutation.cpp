#include <bits/stdc++.h>
using namespace std;

// typedef is used to give datatype a newname
typedef long long ll;
typedef long double ld;
#define INF (__builtin_inff())
#define p(a, b) pair<a, b>
#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define s(a) set<a>
#define ms(a) multiset<a>
#define us(a) unordered_set<a>
#define m(a, b) map<a, b>
#define um(a, b) unordered_map<a, b>
#define mm(a, b) multimap<a, b>

// define is used to give things an alias
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fill(start, end, val) fill(start, end, val)

#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define iteratorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define inputArray(arr, n, i)   \
    for (int i = 0; i < n; i++) \
    {                           \
        input(arr[i])           \
    }
#define inputVector(v, n, i)    \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        v.push_back(x);         \
    }
#define val(x) (*(x))

#define printArray(arr, n, i)   \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << arr[i];         \
        space;                  \
    }                           \
    newline;
#define printVector(v, i)                       \
    for (auto i = v.begin(); i != v.end(); i++) \
    {                                           \
        cout << val(i);                         \
        space;                                  \
    }                                           \
    newline;
#define space cout << " ";
#define newline cout << "\n";

const ll MOD = 1e9 + 7;

bool comparator(p(int, int) a, p(int, int) b)
{
    return (a.first < b.first);
}

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})
// vector<int> v({SIZE OF VECTOR})

int main()
{
    FASTIO;
    tests(t)
    {
        int n;
        cin >> n;
        v(int) arr;
        inputVector(arr, n, i);
        v(bool) canBeMade(n + 1, false);

        iteratorloop(arr, i)
        {
            int value = val(i);
            while (value > 0)
            {
                if (value <= n && canBeMade[value] == false)
                {
                    canBeMade[value] = true;
                    break;
                }
                value /= 2;
            }
        }
        bool flag = true;
        loop(i,1,n)
        {
            if (canBeMade[i] == false)
            {
                cout << "NO";
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES";
        }
        newline;
    }
    return 0;
}