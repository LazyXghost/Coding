#include <bits/stdc++.h>
using namespace std;

#define v(a) vector<a>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define iteratorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define val(x) (*(x))
#define newline cout << "\n";

struct solution
{
    int n, m;
    v(v(int)) graph;
    v(int) direction, edges;
    bool answerPossible = true;
    solution()
    {
        cin >> n >> m;
        graph.resize(n + 1);
        edges.resize(m);
        direction.resize(n + 1, -1);
        int x, y;
        loop(i, 1, m)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
            edges[i-1] = x;
        }
        direction[1] = 0;
        dfs(1);
        if (answerPossible)
        {
            cout << "YES\n";
            loop(i,0,m-1)
                cout << 1 - direction[edges[i]];
            newline;
        }
        else
            cout << "NO\n";
    }
    void dfs(int u)
    {
        iteratorloop(graph[u], i)
        {
            if (!answerPossible)
                break;

            int v = val(i);
            if (direction[v] == -1)
            {
                direction[v] = 1 - direction[u];
                dfs(v);
            }
            else if (direction[v] == direction[u])
                answerPossible = false;
        }
    }
};

int main()
{
    FASTIO;
    solution sol;
    return 0;
}