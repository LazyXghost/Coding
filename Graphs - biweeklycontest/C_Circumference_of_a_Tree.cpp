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

int findDiameter(v(v(int)) & tree, int n)
{
    queue<int> q;
    int vertex = 1, runCount = 0;
    v(int) visited(n + 1),parent(n + 1);
diameterloop:
    runCount++;
    fill(visited.begin(), visited.end(), 0);
    fill(parent.begin(), parent.end(), 0);
    q.push(vertex);
    visited[vertex] = 1;
    while (!q.empty())
    {
        vertex = q.front();
        q.pop();
        iteratorloop(tree[vertex], i)
        {
            if (visited[val(i)] == 0)
            {
                parent[val(i)] = vertex;
                q.push(val(i));
                visited[val(i)] = 1;
            }
        }
    }
    if (runCount == 1)
        goto diameterloop;

    int res = 0;
    while (parent[vertex] != 0)
    {
        vertex = parent[vertex];
        res++;
    }
    return res;
}

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    cout << 3 * findDiameter(tree, n);
    newline;
    return 0;
}