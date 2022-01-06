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
        input(x);               \
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

const ll MOD = 998244353;

bool comparator(p(int, int) a, p(int, int) b)
{
    return (a.first < b.first);
}

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})
// vector<int> v({SIZE OF VECTOR})

ll power(ll n, ll r)
{
    ll res = 1;
    n = n % MOD;
    while (r > 0)
    {
        if (r & 1)
            res = (res * n) % MOD;
        r = r >> 1;
        n = (n * n) % MOD;
    }
    return res;
}

void doPartition(v(v(int)) & graph, v(int) & side)
{
    int n = graph.size() - 1;
    bool isPartible = true;
    ll res = 1;
    loop(i, 1, n)
    {
        if (side[i] == -1)
        {
            int sidezero = 0, sideone = 0;
            if (graph[i].size() == 0)
            {
                sidezero = 1;
            }
            else
            {
                queue<int> q;
                q.push(i);
                side[i] = 0;
                sidezero++;
                while (!q.empty() && isPartible)
                {
                    int u = q.front();
                    q.pop();
                    iteratorloop(graph[u], i)
                    {
                        int v = val(i);
                        if (side[v] == -1)
                        {
                            q.push(v);
                            side[v] = 1 - side[u];
                            if (side[v] == 1)
                                sideone++;
                            else
                                sidezero++;
                        }
                        else if (side[v] == side[u])
                        {
                            isPartible = false;
                            break;
                        }
                    }
                }
                if (!isPartible)
                    break;
            }

            res = (res * ((power(2, sideone) + power(2, sidezero)) % MOD)) % MOD;
        }
    }
    if (!isPartible)
        res = 0;
    cout << res;
    newline;
}

int main()
{
    FASTIO;
    tests(t)
    {
        int n, m;
        cin >> n >> m;
        v(v(int)) graph(n + 1);
        v(int) side(n + 1, -1);
        loop(i, 0, m - 1)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        doPartition(graph, side);
    }
    return 0;
}