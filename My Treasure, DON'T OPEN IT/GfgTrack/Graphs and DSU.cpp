#include <bits/stdc++.h>
using namespace std;

// typedef gives datatype a newname
typedef long long ll;
typedef long double ld;

// define gives things an alias
#define p(a, b) pair<a, b>
#define pii pair<int, int>

#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vvpii vector<vector<pair<int, int>>>
// vector<int> v({SIZE OF VECTOR})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})

#define pq(a) priority_queue<a>
#define pq(a, b) priority_queue<a, vector<a>, b>
// priority_queue<int>
// priority_queue<pair<int,int>> - ORDERING BY FIRST ELEMENT(if first elements are same then ordering by second elements)
// priority_queue<pair<int,int>,vector<pair<int,int>>,{COMPARATOR}>

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
// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})

#define removeScientific cout << fixed;
#define precision(a) cout << setprecision(a);

#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b, inc) for (int i = a; i <= b; i += inc)
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

class sorting
{
    string func = "";
    int order = 1;

public:
    sorting(string a = "", int b = 1)
    {
        func = a;
        order = b;
    }
    void singleSort(vector<int> &first)
    {
        sort(first.begin(), first.end(), [&](int A, int B) -> bool
             {
            bool res;
            if(order == -1)
                res = A>B;
            else
                res = A<B;
            return res; });
    }
    void sortOnBasis(vector<int> &first, vector<int> &second)
    {
        int n = first.size();
        vector<int> indices(n), firstsorted(n), secondsorted(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int A, int B) -> bool
             {
            bool res;
            if (func == ""){
                if(order == 1)
                    res = second[A] < second[B];
                else
                    res = second[A] > second[B];
            }
            else{
                if(func == "-"){
                    if(order == 1)
                        res = second[A]-first[A] < second[B]-first[B];
                    else
                        res = second[A]-first[A] > second[B]-first[B];
                }
                else if(func == "+"){
                    if(order == 1)
                        res = second[A]+first[A] < second[B]+first[B];
                    else
                        res = second[A]+first[A] > second[B]+first[B];
                }
                else{
                    if(order == 1){
                        
                    }
                    else{
                        
                    }
                    // custom function
                    // res = abs(second[A]-first[A]) < abs(second[B]-first[B]);
                }
            }
            return res; });
        for (int i = 0; i < n; i++)
        {
            firstsorted[i] = first[indices[i]];
            secondsorted[i] = second[indices[i]];
        }
        first = firstsorted;
        second = secondsorted;
    }
};
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
        // unordered_map<pair<int,int>,int,HASH>mp;
    }
};
struct pqComp
{
    constexpr bool operator()(
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept
    {
        return a.second < b.second;
    }
};
bool vComp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first; // increasing order
    // return a.first > b.first; // decreasing order
}

// ================================= BFS =============================================
v(v(int)) graph;
int n;
v(int) vis(n + 1, 0), dep(n + 1, INF), par(n + 1, -1);
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dep[s] = 0;
    par[s] = -1;
    vis[s] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // don't mark visited here! (why? bug!)
        iteratorloop(graph[u], i)
        {
            int v = val(i);
            // if (dep[v]==INF)  // if we use depth than we don't need visited array
            if (!vis[v])
            {
                q.push(v);
                dep[v] = dep[u] + 1;
                par[v] = u;
                vis[v] = 1;
            }
        }
    }
}
// to solve police thief problem we can run bfs from thieve and in case of
// directed graph we can reverse edges

// for multi source bfs push all the multisources in the queue and mark them all visited
// this is same as having dummy source as parent of all the polices

const int N = 1000, M = 1000;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};        // four neighbours
int kx[5] = {-2, -1, 1, 2, 2}, ky[5] = {1, 2, 2, 1, -1}; // knight moves in case of chessboard
int dist[N][M];
bool checkIfNotOutsideGrid(int x, int y)
{
    return (x < N && x >= 0 && y < M && y >= 0);
}
void gridbfs(v(p(int, int)) & st)
{
    queue<p(int, int)> q;

    // initialisition loop for multisource bfs by pushing them in single queue
    iteratorloop(st, i)
    {
        p(int, int) source = val(i);
        dist[source.first][source.second] = 0;
        q.push(source);
    }

    // running simple bfs with additional logic according to question
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        loop(i, 0, 3, 1)
        { // instead of constructing graph use FOR loop for 4 edges
            int tempx = x + dx[i], tempy = y + dy[i];
            if (checkIfNotOutsideGrid(tempx, tempy) && dist[tempx][tempy] == INF)
            {
                dist[tempx][tempy] = dist[x][y] + 1;
                q.push({tempx, tempy});
            }
        }
    }
}
// ===================================================================================

// ================================== DFS ============================================
int n;
v(int) vis(n + 1, 0), lev(n + 1, 0), par(n + 1, -1);
v(v(int)) graph(n + 1);
void dfs(int u)
{
    vis[u] = true;
    // if(graph[u].size()==0){
    //     height[u] = 0;
    // }
    iteratorloop(graph[u], i)
    {
        int v = val(i);
        if (!vis[v])
        {
            lev[v] = lev[u] + 1;
            par[v] = u;
            dfs(v);
            // height(v) = height[u]+1;
        }
    }
}

// -------------- NO OF COMPONENTS -------------------
int NoOfComponents()
{
    int no_of_comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            // whenever we find a node no visited by this loop then it will be new component
            no_of_comp++;
            dfs(i);
        }
    }
    return no_of_comp;
}
// ---------------------------------------------------

// ----------- TIMERS + TREE VERSION DFS -------------
// this implementation is only for trees since we are not maintaining a visited array
// and only checking the instantaneous parent
int timer = 0;
v(int) tin, tout;
void DFS(int u, int p = -1)
{
    tin[u] = timer++;
    iteratorloop(graph[u], i)
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

// ------------------- GRID DFS -----------------------
struct gridDfs
{
    int n, m;
    v(v(int)) grid;
    v(int) dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    queue<pair<int, int>> allSources;
    v(v(bool)) vis;
    gridDfs()
    {
        cin >> n >> m;
        grid.resize(n);
        loop(i, 0, n - 1, 1)
        {
            loop(j, 0, m - 1, 1)
            {
                int x;
                cin >> x;
                grid[i].push_back(x);
            }
        }
        vis.resize(n, v(bool)(m, false));
        dfs({n - 1, m - 1});

        // push all the sources in allSources queue first
        bool SourceConnectedToEnd = true;
        while (!allSources.empty())
        {
            p(int, int) pos = allSources.front();
            allSources.pop();
            if (vis[pos.first][pos.second] == false)
                SourceConnectedToEnd = false;
        }
        if (SourceConnectedToEnd)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    void dfs(p(int, int) u)
    {
        int x = u.first, y = u.second;
        vis[x][y] = true;
        loop(pos, 0, 3, 1)
        {
            int tempx = x + dx[pos], tempy = y + dy[pos];
            if (insideGrid(tempx, tempy) && vis[tempx][tempy] == false && allowed(tempx, tempy))
                dfs({tempx, tempy});
        }
    }
    bool allowed(int a, int b)
    {
        // logic to check if the grid checkbox is allowed
        return true;
    }
    bool insideGrid(int a, int b)
    {
        return a >= 0 && a < n && b >= 0 && b < m;
    }
};
// ----------------------------------------------------
// ==================================================================================

// ============================== LCA ===============================
struct LCA
{
    int n, LOG, timer = 0;
    v(v(int)) graph, ancestor;
    v(int) dep, tin, tout;
    void init(int x)
    {
        n = x;
        timer = 0;
        LOG = ceil(log2(n));
        graph.resize(n + 1);
        ancestor.resize(n + 1, v(int)(LOG + 1));
        dep.assign(n + 1, 0);
        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);

        loop(i, 1, n, 1)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        dfs(1);
        pre(1, 1);
    }
    void dfs(int u, int p = -1)
    {
        tin[u] = timer++;
        iteratorloop(graph[u], i)
        {
            int v = val(i);
            // in case of tree we don't need visited array
            if (v == p)
                continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
        tout[u] = timer++;
    }
    void pre(int a, int b)
    {
        ancestor[a][0] = b;
        // setting up the ancestor 2d vector for kth ancestor problems
        loop(v, 1, n, 1)
        {
            // running loop for the max bit ancestor like 2^5 -> 32
            // so running loop 5 times for LOG = 5
            loop(bit, 1, LOG, 1)
            {
                int u = ancestor[v][bit - 1];
                // u is 2^(bit-1)
                if (u == -1)
                    ancestor[v][bit] = -1;
                // if ancestor doesn't exist then marking it -1
                else
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
    v(v(int)) graph;
    v(bool) vis;
    v(int) dep, par, centers;
    int mxdep, mxdepv;
    graphCenters()
    {
        cin >> n;
        graph.resize(n + 1);
        vis.resize(n + 1);
        dep.resize(n + 1);
        par.resize(n + 1);
        int x, y;
        loop(i, 1, n - 1, 1)
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
        iteratorloop(graph[u], i)
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
    v(v(int)) graph;
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
        loop(u, 1, n, 1)
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
// find centroids using sizes of components remaining after deletion of each vertex

// ==================================================================

// ======================= TOPO SORT OF DAG =========================
stack<int> topoStack;
void topoSortCall()
{
    // reverse loop so that component having max value root gets first inside stack
    // or last while printing
    loop(i, n, 1, -1) if (vis[i] == false)
        topoSort(i);
}
void topoSort(int u)
{
    vis[u] = true;
    iteratorloop(graph[u], i)
    {
        int v = val(i);
        if (vis[v] == false)
            topoSort(v);
    }
    topoStack.push(u);
}
// ==================================================================

// ======================= SHORTEST PATH ============================
struct shortestPath
{
    int n, m, src;
    vvpii graph;
    vi dist, vis, par;
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
        loop(i, 1, n - 1, 1)
        {
            loop(curr_node, 1, n, 1)
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
        loop(curr_node, 1, n, 1)
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
    vv(int) graph;
    vi par, vis, cyclepar;
    vpii storage;
    v(bool) recStack;
    dsu st;

    findCycles()
    {
        cin >> n >> m;
        graph.resize(n + 1);

        loop(i, 0, m - 1, 1)
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
        iteratorloop(graph[u], i)
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
            iteratorloop(graph[u], i)
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
    v(v(int)) graph, trgraph;
    v(int) cost, od;
    v(bool) vis;
    stack<int> scc;
    kosaraju()
    {
        int m;
        cin >> n;
        graph.resize(n + 1);
        trgraph.resize(n + 1);
        cost.resize(n + 1, -1);
        vis.resize(n + 1, false);

        loop(i, 1, n, 1)
                cin >>
            cost[i];
        cin >> m;
        int x, y;
        loop(i, 1, m, 1)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            trgraph[y].push_back(x);
        }

        loop(i, 1, n, 1)
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
    }

    void stackEmpty()
    {
        while (!scc.empty())
        {
            cout << scc.top() << " ";
            scc.pop();
        }
        newline;
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
// ==================================================================

// ============================= DSU ================================

class dsu
{
    um(int, int) parent, size;

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
