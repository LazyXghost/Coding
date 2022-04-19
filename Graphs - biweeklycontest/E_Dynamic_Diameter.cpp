#include <bits/stdc++.h>
using namespace std;

// typedef is used to give datatype a newname
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define um(a, b) unordered_map<a, b>
#define us(a) unordered_set<a>

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

v(int) dep, par, centers;
v(v(int)) graph;
int mxdep, mxv;
int n;
int diameter;

void dfs(int u)
{
    iteratorloop(graph[u], i)
    {
        int v = val(i);
        if (dep[v] == -1)
        {
            dep[v] = dep[u] + 1;
            par[v] = u;
            dfs(v);
        }
    }
}

void calldfs(int s)
{
    n = graph.size() - 1;
    fill(dep.begin(), dep.end(), -1);
    fill(par.begin(), par.end(), -1);
    dep[s] = 0;
    dfs(s);

    mxdep = dep[0];
    mxv = 0;
    loop(i, 1, n)
    {
        if (dep[i] > mxdep)
        {
            mxdep = dep[i];
            mxv = i;
        }
    }
}

void findCenters()
{
    int distance = 0;
    while (par[mxv] != -1)
    {
        mxv = par[mxv];
        distance++;
        if (distance == diameter / 2 || distance == (diameter + 1) / 2)
            centers.push_back(mxv);
    }
}

void findAnswer()
{
    int n = graph.size() - 1;
    dep.resize(n + 1);
    par.resize(n + 1);

    if (n == 1)
    {
        cout << 1;
        newline;
    }
    else
    {
        calldfs(1);
        calldfs(mxv);
        diameter = mxdep;
        findCenters();

        v(int) finalDepths(n + 1, -1);
        iteratorloop(centers, i)
        {
            calldfs(val(i));
            loop(i, 1, n)
                finalDepths[i] = max(finalDepths[i], dep[i]);
        }
        loop(i, 1, n)
        {
            int res = diameter;
            if (centers.size() == 1 && finalDepths[i] >= diameter / 2)
                    res++;
            if (centers.size()!=1 && finalDepths[i] > diameter / 2)
                    res++;
            cout << res;
            newline;
        }
    }
}

int main()
{
    FASTIO;
    int n;
    input(n);
    graph.resize(n + 1);
    loop(i, 0, n - 2)
    {
        int x, y;
        input(x);
        input(y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    findAnswer();
    return 0;
}