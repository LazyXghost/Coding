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

struct solution
{
    int n;
    v(v(int)) graph;
    v(bool) visited;
    stack<int> topoStack;
    bool impossible = false;

    solution(int noOfWords)
    {
        n = 26;
        graph.resize(n + 1);
        visited.assign(n + 1, true);

        string arr[noOfWords];
        loop(i, 0, noOfWords - 1)
                cin >>
            arr[i];
        loop(i, 1, noOfWords - 1)
        {
            string prev = arr[i - 1], curr = arr[i];
            p(int, int) edge = findEdge(prev, curr);
            if (edge.first != -1)
            {
                graph[edge.first].push_back(edge.second);
                visited[edge.first] = false;
                visited[edge.second] = false;
            }
        }
    }
    p(int, int) findEdge(string &a, string &b)
    {
        int ind = 0;
        bool edgeExists = true;
        while (a[ind] == b[ind] && edgeExists)
        {
            ind++;
            if (ind >= min(a.size(), b.size())){
                if(a.size()>b.size()){
                    impossible = true;
                }
                edgeExists = false;
            }
        }

        if (edgeExists)
            return {a[ind] - 96, b[ind] - 96};
        return {-1, -1};
    }
    void printGraph()
    {
        loop(u, 1, n)
        {
            cout << u << "->";
            printVector(graph[u], i);
        }
    }

    void isCyclic()
    {
        v(bool) visitedCopy = visited;
        v(bool) recStack = visited;

        for (int i = 1; i < n; i++)
            if (visitedCopy[i] == false && isCyclicUtil(i, visitedCopy, recStack))
            {
                impossible = true;
                return;
            }

        return;
    }
    bool isCyclicUtil(int u, v(bool) & visitedCopy, v(bool) & recStack)
    {
        if (visitedCopy[u] == false)
        {
            // Mark the current node as visitedCopy and part of recursion stack
            visitedCopy[u] = true;
            recStack[u] = true;

            // Recur for all the vertices adjacent to this vertex
            iteratorloop(graph[u], i)
            {
                int v = val(i);
                if (!visitedCopy[v] && isCyclicUtil(v, visitedCopy, recStack))
                    return true;
                else if (recStack[v])
                    return true;
            }
        }
        recStack[u] = false; // remove the vertex from recursion stack
        return false;
    }

    void topoSort()
    {
        for (int i = n; i >= 1; i--)
            if (visited[i] == false)
                topoSortUtil(i);
    }
    void topoSortUtil(int u)
    {
        visited[u] = true;
        iteratorloop(graph[u], i)
        {
            int v = val(i);
            if (visited[v] == false)
                topoSortUtil(v);
        }
        topoStack.push(u);
    }
};

int main()
{
    FASTIO;
    int noOfWords;
    cin >> noOfWords;
    solution sol(noOfWords);
    string res = "";
    if (!sol.impossible)
        sol.isCyclic();
    if (sol.impossible)
        res = "Impossible";
    else
    {
        sol.topoSort();

        v(int) finalres;
        stack<int> topoStack = sol.topoStack;
        string tempres = "";
        us(char) presentInRes;

        while (!topoStack.empty())
        {
            char letter = topoStack.top() + 96;
            topoStack.pop();
            tempres += letter;
            presentInRes.insert(letter);
        }
        tempres += "~";
        // cout << "Tempres is" << tempres;
        // newline;
        int ind = 0, i = 1;
        while (i < 27)
        {
            char currletter = i + 96;
            if (presentInRes.find(currletter) == presentInRes.end())
            {
                if (currletter < tempres[ind])
                {
                    res += currletter;
                    i++;
                }
                else
                    res += tempres[ind++];
            }
            else
                i++;
        }
        int size = tempres.size();
        loop(i, ind, size - 2)
        {
            res += tempres[i];
        }
    }
    cout << res;
    newline;
    return 0;
}