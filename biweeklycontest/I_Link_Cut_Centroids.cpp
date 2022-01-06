#include <bits/stdc++.h>
using namespace std;

// typedef is used to give datatype a newname
typedef long long ll;
typedef long double ld;
#define INF 1e10
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

struct graphCentroids
{
    int n;
    vv(int) graph;
    v(int) par, centroids, size;
    v(p(int, int)) deletionsizes;

    graphCentroids()
    {
        cin >> n;
        graph.resize(n + 1);
        par.resize(n + 1);
        size.resize(n + 1);
        deletionsizes.resize(n + 1, {n, n});
        int x, y;
        loop(i, 1, n - 1)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        fill(par.begin(), par.end(), -1);
        fill(size.begin(), size.end(), 1);
        size[0] = -1;
        dfsWithSize(1, -1);
        findCentroids();
    }
    void findCentroids()
    {
        int res = 1e6;
        loop(u, 1, n)
        {
            int sizechild = -1, sizepar = -1;
            auto it = graph[u].begin();
            if (graph[u].size() == 1)
            {
                if (val(it) == par[u])
                    sizepar = n - size[u];
                else
                    sizechild = size[val(it)];
            }
            else
            {
                if (val(it) == par[u])
                    it++;
                sizechild = size[val(it)];

                iteratorloop(graph[u], i)
                {
                    int v = val(i);
                    if (v == par[u])
                        sizepar = n - size[u];
                    else
                        sizechild = max(sizechild, size[v]);
                }
            }
            deletionsizes[u] = {sizepar, sizechild};
            res = min(res, max(sizechild, sizepar));
        }
        loop(u, 1, n)
        {
            p(int, int) sz = deletionsizes[u];
            if (max(sz.first, sz.second) == res)
            {
                centroids.push_back(u);
            }
        }
    }
    void dfsWithSize(int u, int p)
    {
        iteratorloop(graph[u], i)
        {
            int v = val(i);
            if (v == p)
                continue;
            par[v] = u;
            dfsWithSize(v, u);
            size[u] += size[v];
        }
    }
};

int main()
{
    FASTIO;
    tests(t)
    {
        graphCentroids solution;
    }
    return 0;
}