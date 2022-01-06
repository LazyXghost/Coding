#include <bits/stdc++.h>
using namespace std;

// typedef gives datatype a newname
typedef long long ll;

// define gives things an alias
typedef long double ld;
#define p(a, b) pair<a, b>
#define v(a) vector<a>
#define q(a) queue<a>
#define st(a) stack<a>
#define s(a) set<a>
#define ms(a) multiset<a>
#define us(a) unordered_set<a>
#define m(a, b) map<a, b>
#define mm(a, b) multimap<a, b>
#define um(a, b) unordered_map<a, b>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fill(start, end, val) fill(start, end, val)
#define fill(start, end, val) fill(start, end, val)
#define removeScientific cout << fixed;
#define precision(a) cout << setprecision(a);

#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b, inc) for (int i = a; i <= b; i += inc)
#define iteratorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
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
const ll INF = 1e15;

bool comparator(p(int, int) a, p(int, int) b)
{
    return (a.first < b.first);
}

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})
// vector<int> v({SIZE OF VECTOR})

struct solution
{
    int n;
    v(int) arr;
    string inversions;
    solution()
    {
        cin >> n;
        loop(i, 0, n - 1, 1)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        countInversions();
        int m;
        cin >> m;
        loop(i, 0, m - 1, 1)
        {
            int l, r;
            cin >> l >> r;
            int swaps = (r - l + 1) / 2;
            if (swaps % 2 != 0)
            {
                if (inversions == "even")
                    inversions = "odd";
                else
                    inversions = "even";
            }
            cout << inversions;
            newline;
        }
    }
    void countInversions()
    {
        int res = 0;
        loop(i, 0, n - 2, 1)
            loop(j, i + 1, n - 1, 1)
                if (arr[j] < arr[i])
                    res++;
        if (res % 2 == 0)
            inversions = "even";
        else
            inversions = "odd";
    }
};
int main()
{
    FASTIO;
    solution sol;
    return 0;
}