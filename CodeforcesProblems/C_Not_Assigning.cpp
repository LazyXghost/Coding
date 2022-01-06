#include <bits/stdc++.h>
using namespace std;

// typedef gives datatype a newname
typedef long long ll;
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

// define gives things an alias
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
        cin >> arr[i]           \
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

struct solution
{
    int n;
    v(v(int)) graph;
    v(int) par, dep;
    solution()
    {
        cin >> n;
        graph.resize(n + 1);
        dep.resize(n + 1, 0);
        par.resize(n + 1, -1);
        int x, y;
        v(p(int,int)) storage;
        loop(i, 0, n - 2)
        {
            cin >> x >> y;
            storage.push_back({x,y});
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        bool exists = true;
        loop(u, 1, n)
        {
            if (graph[u].size() > 2)
            {
                exists = false;
                break;
            }
        }

        if (exists)
        {
            dfs(1, -1);
            int mxdep = dep[1], mxv = 1;
            loop(i, 1, n){
                if(dep[i]>mxdep){
                    mxv = i;
                    mxdep = dep[i];
                }
            }
            fill(dep.begin(), dep.end(), 0);
            fill(par.begin(), par.end(), -1);

            dfs(mxv,-1);
            mxdep = dep[1];
            mxv = 1;
            loop(i, 1, n){
                if(dep[i]>mxdep){
                    mxv = i;
                    mxdep = dep[i];
                }
            }

            um(int,int) edgeweight;
            int choose = 2;
            while(par[mxv]!=-1){
                edgeweight.insert({mxv, choose});
                choose = 7 - choose;
                mxv = par[mxv];
            }

            iteratorloop(storage, i){
                p(int,int) v = val(i);
                int x= v.first;
                int y= v.second;
                if(y == par[x]){
                    cout<< edgeweight[x]<<" ";
                }
                else{
                    cout<<edgeweight[y]<<" ";
                }
            }
            newline;
        }
        else
        {
            cout << "-1";
            newline;
        }
    }
    void dfs(int u, int p){
        iteratorloop(graph[u], i){
            int v = val(i);
            if(v == p) continue;
            dep[v] = dep[u] + 1;
            par[v] = u;
            dfs(v, u);
        }
    }
};

int main()
{
    FASTIO;
    tests(t)
    {
        solution sol;
    }
    return 0;
}