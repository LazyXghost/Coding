#include <bits/stdc++.h>
using namespace std;

#define INF (__builtin_inff ())
#define p(a,b) pair<int,int>
#define v(a) vector<a>
#define um(a, b) unordered_map<a, b>
#define us(a) unordered_set<a>
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define iteratorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define val(x) (*(x))
#define space cout<<" "
#define newline cout<<"\n"

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
                dep[v] = dep[u]+1;
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

const int N=1000,M=1000;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0}; //four neighbours
int kx[5] = {-2,-1,1,2,2},ky[5] = {1,2,2,1,-1}; //knight moves in case of chessboard
int dist[N][M];
bool checkIfNotOutsideGrid(int x, int y){
    return (x<N && x>=0 && y<M && y>=0);
}
void gridbfs(v(p(int,int)) &st){
    queue<p(int,int)> q;
    iteratorloop(st,i){
        p(int,int) source= val(i);
        dist[source.first][source.second] = 0;
        q.push(source);
    }

    while (!q.empty())
    {
        int x = q.front().first,y = q.front().second;
        q.pop();
        loop(i,0,4){ //instead of constructing graph use FOR loop for 4 edges
            int tempx = x+dx[i], tempy = y+dy[i];
            if(checkIfNotOutsideGrid(tempx,tempy) && dist[tempx][tempy] == INF){
                dist[tempx][tempy] = dist[x][y]+1;
                q.push({tempx,tempy});
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
        if (!vis[i]){
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
v(int) tin,tout;
void DFS(int u, int p = -1){
    tin[u] = timer++;
    iteratorloop(graph[u],i){
        int v = val(i);
        if(v == p) continue;
        DFS(v, u);
    }
    tout[u] = timer++;
}
// APPLICATION OF TIN AND TOUT
// find if one node is ancestor of other node
// if(tin[u]<tin[v] && tout[u]>tout[v]){
//     u is ancestor of v
// }
// find left bottom most and right bottom most node
// left bottom most node has min tout since its dfs completes first
// right bottom most node has max tin since its dfs is called last
// ----------------------------------------------------

// ==================================================================================

// ======================= PRINTING =============================
void printGraph(v(v(int)) & graph)
{
    int n = graph.size() - 1;
    loop(i, 1, n)
    {
        cout<<i << "->";
        iteratorloop(graph[i], j)
        {
            cout<<val(j);
            space;
        }
        newline;
    }
}
// ==============================================================

// ======================= INPUTING =============================
void inputGraph(v(v(int)) & graph, int n, int m)
{
    graph.resize(n + 1);
    loop(i, 1, m)
    {
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}
// ==============================================================







// ======= PROBLEMS =========
// void calldfs(int s)
// {
//     n = graph.size() - 1;
//     fill(dep.begin(), dep.end(), -1);
//     fill(par.begin(), par.end(), -1);
//     dep[s] = 0;
//     dfs(s);

//     mxdep = dep[0];
//     mxv = 0;
//     loop(i, 1, n)
//     {
//         if (dep[i] > mxdep)
//         {
//             mxdep = dep[i];
//             mxv = i;
//         }
//     }
// }

// void findCenters()
// {
//     int distance = 0;
//     while (par[mxv] != -1)
//     {
//         mxv = par[mxv];
//         distance++;
//         if (distance == diameter / 2 || distance == (diameter + 1) / 2)
//             centers.push_back(mxv);
//     }
// }
// ===========================