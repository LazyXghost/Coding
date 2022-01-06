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
#define loop(i, a, b) for (int i = a; i <= b; i++)
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
    int n, m, q;
    v(us(int)) graph;
    int livingCount;
    solution()
    {
        cin >> n >> m;
        graph.resize(n + 1);
        int x, y;
        int small, big;
        loop(i, 0, m - 1)
        {
            cin >> x >> y;
            small = min(x, y);
            big = max(x, y);

            graph[small].insert(big);
        }

        findLivingCount();

        cin >> q;
        loop(i, 0, q - 1)
        {
            int query;
            cin >> query;
            if (query == 1 || query == 2)
            {
                cin >> x >> y;
                small = min(x, y);
                big = max(x, y);

                if (query == 1)
                {
                    if (graph[small].size() == 0)
                        livingCount--;
                    graph[small].insert(big);
                }
                else
                {
                    graph[small].erase(graph[small].find(big));
                    if (graph[small].size() == 0)
                        livingCount++;
                }
            }
            else
            {
                cout << livingCount;
                newline;
            }
        }
    }
    void findLivingCount()
    {
        int res = 0;
        loop(u, 1, n ) if (graph[u].size() == 0)
            res++;
        livingCount = res;
    }
};

int main()
{
    // FASTIO;
    solution sol;
    return 0;
}