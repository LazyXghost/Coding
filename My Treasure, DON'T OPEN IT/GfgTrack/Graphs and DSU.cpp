#include<bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define val(x) (*(x))
const long long INF = INFINITY;

// to solve police thief problem we can run bfs from thieve and in case of
// directed graph we can reverse edges

// for multi source bfs push all the multisources in the queue and mark them all visited
// this is same as having dummy source as parent of all the polices

// ----------- TIMERS + TREE VERSION DFS -------------
// this implementation is only for trees since we are not maintaining a visited array
// and only checking the instantaneous parent
int timer = 0;
vector<int> tin, tout;
void DFS(int u, int p = -1)
{
    tin[u] = timer++;
    for(auto i = graph[u].begin();i!=graph[u].end();i++)
    {
        int v = val(i);
        if (v == p)
            continue;
        DFS(v, u);
    }
    tout[u] = timer++;
}
// APPLICATION OF TIN AND TOUT
// find if one node is ancestor of other node using timers(IN LCA)
/*  find left bottom most and right bottom most node
    left bottom most node has min tout since its dfs completes first
    right bottom most node has max tin since its dfs is called last */
// ----------------------------------------------------
// ============================== LCA ===============================
struct LCA
{
    int n, LOG, timer = 0;
    vector<vector<int>> graph, ancestor;
    vector<int> dep, tin, tout;
    void init(int x)
    {
        n = x;
        timer = 0;
        LOG = ceil(log2(n));
        graph.resize(n + 1);
        ancestor.resize(n + 1, vector<int>(LOG + 1));
        dep.assign(n + 1, 0);
        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);

        for(int i = 1;i<=n;i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        dfs(1);
        pre();
    }
    void dfs(int u, int p = -1)
    {
        tin[u] = timer++;
        for(auto i = graph[u].begin();i!=graph[u].end();i++)
        {
            int v = val(i);
            // in case of tree we don't need visited array
            if (v == p)
                continue;
            dep[v] = dep[u] + 1;
            ancestor[v][0] = u;
            dfs(v, u);
        }
        tout[u] = timer++;
    }
    void pre()
    {
        ancestor[1][0] = 1;
        // setting up the ancestor 2d vector for kth ancestor problems
        for(int v = 1;v<=n;v++)
        {
            // running loop for the max bit ancestor like 2^5 -> 32
            // so running loop 5 times for LOG = 5
            for(int bit = 1;bit<=LOG;bit++)
            {
                int u = ancestor[v][bit - 1];
                // u is 2^(bit-1)
                // if (u == -1)
                    // ancestor[v][bit] = -1;
                // if ancestor doesn't exist then marking it -1
                // else
                    ancestor[v][bit] = ancestor[u][bit - 1];
                // dividing 2^bit ancestor in 2^(bit-1) + 2^(bit-1)
            }
        }
    }
    bool is_ancestor(int u, int v)
    {
        // using timers to check if u is ancestor of v
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v)
    {
        // check if u or v are LCA
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;

        for (int bit = LOG; bit >= 0; bit--)
        {
            // if it is the ancestor of both then we don't change u
            int ith_ancestor = ancestor[u][bit];

            if (!is_ancestor(ith_ancestor, v))
                u = ith_ancestor;
        }
        return ancestor[u][0];
    }
    int lift(int u, int d)
    {
        // find dth ancestor using ancestor array
        while (d > 0)
        {
            int rise = log2(d);
            u = ancestor[u][rise];
            d -= 1ll << rise;
        }
        return u;
    }
    int dist(int a, int b)
    {
        // we can use lca to find the distance between two nodes
        int lowest_common_ancestor = lca(a, b);
        return dep[a] + dep[b] - 2 * dep[lowest_common_ancestor];
    }
};
// ==================================================================

// ================== CENTERS/CENTROIDS OF GRAPH ====================
struct graphCenters
{
    int n;
    vector<vector<int>> graph;
    vector<bool> vis;
    vector<int> dep, par, centers;
    int mxdep, mxdepv;
    graphCenters()
    {
        cin >> n;
        graph.resize(n + 1);
        vis.resize(n + 1);
        dep.resize(n + 1);
        par.resize(n + 1);
        int x, y;
        for(int i = 1;i<n;i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        findCenters();
    }
    void findCenters()
    {
        dfsUtil(1);
        dfsUtil(mxdepv);

        int distance = 0, diameter = mxdep;
        int u = mxdepv;
        while (u != -1)
        {
            u = par[u];
            distance++;
            if (distance == diameter / 2 || distance == (diameter + 1) / 2)
                centers.push_back(u);
        }
    }
    void dfsUtil(int s)
    {
        fill(vis.begin(), vis.end(), false);
        fill(dep.begin(), dep.end(), -1);
        fill(par.begin(), par.end(), -1);
        dep[s] = 0;

        dfs(s);

        mxdep = dep[1];
        mxdepv = 1;
        loop(i, 2, n, 1)
        {
            if (dep[i] > mxdep)
            {
                mxdep = dep[i];
                mxdepv = i;
            }
        }
    }
    void dfs(int u)
    {
        vis[u] = true;
        for(auto i = graph[u].begin();i!=graph[u].end();i++)
        {
            int v = val(i);
            if (!vis[v])
            {
                dep[v] = dep[u] + 1;
                par[v] = u;
                dfs(v);
            }
        }
    }
};
// just went from diametric end to other end and found mid vertices
struct graphCentroids
{
    int n;
    vector<vector<int>> graph;
    vector<int> par, centroids, size;
    vector<pair<int,int>> deletionsizes;

    graphCentroids()
    {
        cin >> n;
        graph.resize(n + 1);
        par.resize(n + 1);
        size.resize(n + 1);
        deletionsizes.resize(n + 1, {n, n});
        int x, y;
        loop(i, 1, n - 1, 1)
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
        loop(u, 1, n, 1)
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

                for(auto i = graph[u].begin();i!=graph[u].end();i++)
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
        loop(u, 1, n, 1)
        {
            pair<int,int> sz = deletionsizes[u];
            if (max(sz.first, sz.second) == res)
            {
                centroids.push_back(u);
            }
        }
    }
    void dfsWithSize(int u, int p)
    {
        for(auto i = graph[u].begin();i!=graph[u].end();i++)
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
// find centroids using sizes of components remaining after deletion of each vertex

// ==================================================================

// // ======================= TOPO SORT OF DAG =========================
// stack<int> topoStack;
// void topoSortCall()
// {
//     // reverse loop so that component having max value root gets first inside stack
//     // or last while printing
//     loop(i, n, 1, -1) if (vis[i] == false)
//         topoSort(i);
// }
// void topoSort(int u)
// {
//     vis[u] = true;
//     for(auto i = graph[u].begin();i!=graph[u].end();i++)
//     {
//         int v = val(i);
//         if (vis[v] == false)
//             topoSort(v);
//     }
//     topoStack.push(u);
// }
// // ==================================================================

// ======================= SHORTEST PATH ============================
struct shortestPath
{
    int n, m, src;
    vector<vector<pair<int,int>>> graph;
    vector<int> dist, vis, par;
    pq(pii, pqComp) priq;

    shortestPath()
    {
        cin >> n >> m;
        graph.resize(n + 1);
        loop(i, 0, m - 1, 1)
        {
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].push_back({y, w});
            graph[y].push_back({x, w});
        }
        par.resize(n + 1);
        dist.resize(n + 1, INT_MAX);
        vis.resize(n + 1, 0);
        // dijkstra(1);
    }

    /*
    Dijkstra's algorithm
        starting from source we relaxes the distance of each node attached to source first
        now each time we pick the min distance node from prio. queue
        and then relaxes all the nodes attached to the min distance node
    */
    void dijkstra(int src)
    {
        // starting process with making source distance zero and pushing it in queue
        dist[src] = 0;
        par[src] = -1;
        priq.push({src, 0});

        while (!priq.empty())
        {
            int curr_node = priq.top().first, curr_dist = priq.top().second;
            priq.pop();

            // if curr_node has already got min distance means its distance is already minimised
            if (vis[curr_node])
                continue;

            // if it reaches here then found min distance for curr_node and marking it as found
            vis[curr_node] = 1;
            iteratorloop(graph[curr_node], i)
            {
                // checking for ngbr_node if its cost and curr_dist is less than already found distance that is relaxing the neighbour node
                int ngbr_node = val(i).first, ngbr_cost = val(i).second;
                if (curr_dist + ngbr_cost < dist[ngbr_node])
                {
                    // first marking its new distance and parent and then pushing it in priority queue and checking for all its neighbou
                    par[ngbr_node] = curr_node;
                    dist[ngbr_node] = curr_dist + ngbr_cost;
                    priq.push({ngbr_node, dist[ngbr_node]});
                }
            }
        }
    }
    // dijkstra algorithm fails when there are negative weights in graph
    // works for both directed and undirected graphs
    // time complexity is O(Elog(V))
    // all weights should be non - negative
    // In case of negative weights
    //      [1] --------- 3 --------- [2]
    //       \                        /
    //        --- 9 --- [3] --- -7 --
    //      It will first fix 2 but there is another path 1->3->2 which has less weight, this limit is addressed by bellmanFord

    /*
    BellManFord's algorithm-
        pick all the edges in any order and do any possible relaxations
        repeat above process n-1 times , and we will get shortest path of each node
        it take cares if there are negative weights but not in case of negative cycle.
    */
    void bellmanFord(int src)
    {
        dist[src] = 0;
        for(int i = 1;i<n;i++)
        {
            for(int curr_node = 1;curr_node <= n;i++)
            {
                iteratorloop(graph[curr_node], v)
                {
                    pii edge = val(v);
                    int ngbr_node = edge.first, ngbr_dist = edge.second;
                    if (dist[curr_node] + ngbr_dist < dist[ngbr_node])
                        dist[ngbr_node] = dist[curr_node] + ngbr_dist;
                }
            }
            // picking each edge once and relaxing a node if it relaxes
        }
    }
    // time complexity is O(EV)
    // It works for directed graph with negative edges but not for negative cycle
    // In case of negative cycle
    //      [1] --------- 3 --------- [2]
    //       \                        /
    //        --- 4 --- [3] --- -7 --
    //       It can go in loop infinite time and distance will keep on decreasing so there is no smallest path
    // It can detect negative cycle - if on running bellmanford again the relaxing again happens then there must be negative cycle
    bool negativeCycle = false;
    void checkNegCycle(int src)
    {
        for(int curr_node = 1;curr_node <= n;curr_node++)
        {
            iteratorloop(graph[curr_node], v)
            {
                pii edge = val(v);
                int ngbr_node = edge.first, ngbr_dist = edge.second;
                if (dist[curr_node] + ngbr_dist < dist[ngbr_node])
                {
                    // if relaxing again happens after running bellmanford then there must be negative cycle
                    negativeCycle = true;
                    return;
                }
            }
        }
    }
    // bellmanFord works with directed graphs with non negative cycle, it can be made to work with undirected graphs if there are no negative edges by breaking one edge into two directed edges(if undirected edge is negative then breaking it in two directed edges makes a negative cycle)
};
// ==================================================================

// ======================== FINDING CYCLE ===========================
struct findCycles
{
    int n, m;
    vector<vector<int>> graph;
    vector<int> par, vis, cyclepar;
    vector<pair<int,int>> storage;
    vector<bool> recStack;
    dsu st;

    findCycles()
    {
        cin >> n >> m;
        graph.resize(n + 1);

        for(int i = 0;i<m;i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        // first making set of each vertex
        loop(i, 1, n, 1)
            st.make_set(i);

        par.resize(n + 1, -1);
        vis.resize(n + 1, false);
        recStack.resize(n + 1, false);
        dfsForCycles(1, -1);

        bool cyclic = isCyclic();
    }

    /*
    It works for both directed as well as undirected graph

    Basic logic is same as dfs, extra part is using recStack and dsu
    Whenever it finds a cycle in graph, it connects all the vertices of that cycle together
    */
    void dfsForCycles(int u, int p)
    {
        vis[u] = true;
        recStack[u] = true;
        for(auto i = graph[u].begin();i!=graph[u].end();i++)
        {
            int v = val(i);
            if (v == p)
                continue;

            // if it is in rec Stack then this means it is in cycle
            if (recStack[v] == true)
            {
                // using dsu , we do union of all the vertex in cycle
                int curr = u;
                while (curr != v)
                {
                    cyclepar[v] = u;
                    st.union_set(par[curr], curr);
                    curr = par[curr];
                }
            }
            else if (!vis[v])
            {
                par[v] = u;
                dfsForCycles(v, u);
            }
        }
        recStack[u] = false;
    }

    bool isCyclic()
    {
        vis.resize(n + 1, false);
        recStack.resize(n + 1, false);

        for (int i = 1; i < n; i++)
            if (vis[i] == false && isCyclicUtil(i))
                return true;

        return false;
    }
    bool isCyclicUtil(int u)
    {
        if (vis[u] == false)
        {
            // Mark the current node as vis and part of recursion stack
            vis[u] = true;
            recStack[u] = true;

            // Recur for all the vertices adjacent to this vertex
            for(auto i = graph[u].begin();i!=graph[u].end();i++)
            {
                int v = val(i);
                if ((!vis[v] && isCyclicUtil(v)) || recStack[v])
                    return true;
            }
        }
        recStack[u] = false; // remove the vertex from recursion stack
        return false;
    }
};
// =================================================================

// ========================== SCC IN DG ============================
/*
It works only in case of directed graph
Kosaraju's algorithm
    First run dfs and find the vertices having tout in increasing order
    if we run dfs on transposed graph and vertice having max tout
    then it will give single strongly connected component of dag
*/
struct kosaraju
{
    int n;
    vector<vector<int>> graph, trgraph;
    vector<int> cost, od;
    vector<bool> vis;
    stack<int> scc;
    kosaraju()
    {
        int m;
        cin >> n;
        graph.resize(n + 1);
        trgraph.resize(n + 1);
        cost.resize(n + 1, -1);
        vis.resize(n + 1, false);

        for(int i = 1;i<=n;i++)
            cin >> cost[i];
        cin >> m;
        int x, y;
        for(int i = 1;i<=m;i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            trgraph[y].push_back(x);
        }

        for(int i = 1;i<=n;i++)
        {
            if (vis[i] == false)
                dfs(i);
        }

        reverse(od.begin(), od.end());
        vis.assign(n + 1, false);
        trdfs(val(od.begin()));
        for(auto i = od.begin();i!=od.end();i++)
        {
            int v = val(i);
            if (vis[v] == false)
            {
                stackEmpty();
                trdfs(v);
            }
        }
        stackEmpty();
    }

    void stackEmpty()
    {
        while (!scc.empty())
        {
            cout << scc.top() << " ";
            scc.pop();
        }
        cout<<"\n";
    }

    void dfs(int u)
    {
        vis[u] = true;
        for(auto i = graph[u].begin();i!=graph[u].end();i++)
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
        for(auto i = trgraph[u].begin();i != trgraph[u].end();i++)
        {
            int v = val(i);
            if (vis[v] == false)
                trdfs(v);
        }
        scc.push(u);
    }
};
// ==================================================================

// ============================= DSU ================================

class dsu
{
    map<int,int> parent, size;

public:
    // making new set by just initialising the parent of set as the same number
    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }

    // finding the root of the set
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        // return find_set(parent[v]);

        return parent[v] = find_set(parent[v]);
        // 1st optimisization - path compression
        // directly connects all the linear chain nodes to parent
        // 7->5->3->1 ==> 7->1,5->1,3->1
    }

    // making the root of one set as the parent of root of other set will combine two sets
    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            // 2nd optimisation - union by size
            if (size[a] < size[b])
                swap(a, b);

            parent[b] = a;
            size[a] += size[b];
        }
    }

    // returning the size of the set of vertex v
    int find_size(int v)
    {
        return size[find_set(v)];
    }
};
/*
Time complexity -
                            AFTER OPTIMISATION'S
    FIND SET  - O(n)      O(alpha(n)) - almost constant
    MAKE SET  - O(1)              O(1)
    UNION SET - O(n)           O(alpha(n))
*/
//==================================================================
