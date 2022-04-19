#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define v(a) vector<a>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define iteratorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define val(x) (*(x))
#define space cout << " ";
#define newline cout << "\n";

const ll MOD = 1e9 + 7;

struct solution
{
    int n;
    v(v(int)) graph, trgraph;
    v(int) cost, od;
    v(bool) vis;
    stack<int> scc;
    ll rescost = 0, resways = 1;
    solution()
    {
        int m;
        cin >> n;
        graph.resize(n + 1);
        trgraph.resize(n + 1);
        cost.resize(n + 1, -1);
        vis.resize(n + 1, false);

        loop(i, 1, n)
            cin >>cost[i];
        cin >> m;
        int x, y;
        loop(i, 1, m)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            trgraph[y].push_back(x);
        }

        loop(i, 1, n)
        {
            if (vis[i] == false)
                dfs(i);
        }

        reverse(od.begin(), od.end());
        vis.assign(n + 1, false);
        trdfs(val(od.begin()));
        iteratorloop(od, i)
        {
            int v = val(i);
            if (vis[v] == false)
            {
                stackEmpty();
                trdfs(v);
            }
        }
        stackEmpty();
        cout << rescost << " " << resways;
        newline;
    }

    void stackEmpty()
    {
        int mn = INT_MAX, tempways;
        while (!scc.empty())
        {
            if (cost[scc.top()] == mn)
                tempways++;
            else if (cost[scc.top()] < mn)
                tempways = 1;
            mn = min(mn, cost[scc.top()]);
            scc.pop();
        }
        rescost += mn;
        resways = (resways*tempways)%MOD;
    }

    void dfs(int u)
    {
        vis[u] = true;
        iteratorloop(graph[u], i)
        {
            int v = val(i);
            if (vis[v] == false)
                dfs(v);
        }
        od.push_back(u);
    }
    void trdfs(int u)
    {
        vis[u] = true;
        iteratorloop(trgraph[u], i)
        {
            int v = val(i);
            if (vis[v] == false)
                trdfs(v);
        }
        scc.push(u);
    }
};

int main()
{
    FASTIO;
    solution sol;
    return 0;
}