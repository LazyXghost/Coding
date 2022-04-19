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

#define printVector(v, i)                       \
    for (auto i = v.begin(); i != v.end(); i++) \
    {                                           \
        cout << val(i);                         \
        space;                                  \
    }                                           \
    newline;
#define space cout << " ";
#define newline cout << "\n";

v(v(int)) graph;
v(int) dis, par;
um(int, int) sizes;

void bfs(int s)
{
    int n = graph.size() - 1;
    dis.resize(n + 1);
    par.resize(n + 1);
    fill(dis.begin(), dis.end(), -1);
    fill(par.begin(), par.end(), -1);
    queue<int> q;

    q.push(s);
    dis[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int count = 0;
        iteratorloop(graph[u], i)
        {
            int v = val(i);
            if (dis[v] == -1)
            {
                count++;
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
        sizes.insert({u, count});
    }
}

int main()
{
    FASTIO;
    // take input n
    int n;
    cin >> n;
    // take input tree in form of graph having n-1 edges
    graph.resize(n + 1);
    loop(i, 1, n - 1)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // take an array of n integers input
    int arr[n];
    loop(i, 0, n - 1)
    {
        cin >> arr[i];
    }
    // run bfs and find distance array
    bfs(1);
    // printVector(dis,i);

    queue<int> q;
    q.push(arr[0]);
    string res = "";
    int flag = 1;
    loop(i, 1, n - 1)
    {
        int u,v = arr[i];
        if (q.size() == 0)
            flag = 0;
        else
            u = q.front();

        while (flag==1 && sizes[u] == 0)
        {
            if (q.size() != 0)
                q.pop();

            if (q.size() == 0)
                flag = 0;
            else
                u = q.front();
        }

        if (flag == 1 && u == par[v])
        {
            q.push(v);
            sizes[u]--;
            if (sizes[u] == 0)
                q.pop();
        }
        else
        {
            res = "No";
            break;
        }
    }
    if (res == "")
        res = "Yes";
    cout << res;
    newline;
    return 0;
}