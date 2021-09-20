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

#define print(x) cout << x;
#define input(x) cin >> x;
#define space cout << " ";
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

int findAnswer(v(v(int)) &graph)
{
    us(int) notvisited;
    loop(i, 1, graph.size() - 1)
    {
        if (graph[i].size() > 0)
            notvisited.insert(i);
    }
    // iteratorloop(notvisited, i)
    // {
    //     print(val(i));
    //     space;
    // }
    // newline;

    int vertex = 1,connected_components = 1;
    queue<int> q;

    q.push(vertex);
    notvisited.erase(notvisited.find(vertex));
    while (!q.empty() || !notvisited.empty())
    {
        if(q.empty()){
            connected_components++;
            q.push(val(notvisited.begin()));
            notvisited.erase(notvisited.begin());
        }
        vertex = q.front();
        q.pop();
        iteratorloop(graph[vertex], i)
        {
            if (notvisited.find(val(i)) != notvisited.end())
            {
                q.push(val(i));
                notvisited.erase(notvisited.find(val(i)));
            }
        }
    }
    return connected_components;
}

int main()
{
    FASTIO;
    int n;
    input(n);
    v(string) s(n);
    string x;
    loop(i, 0, n - 1)
        cin >>s[i];
    int totalVertices = n + 26;
    vector<vector<int>> graph(totalVertices + 1);
    for (int i = 0; i < n; i++)
    {
        x = s[i];
        loop(j, 0, x.size() - 1)
        {
            char letter = x[j];
            int mappingVertex = ((int)letter) - 97 + n + 1;
            graph[i + 1].push_back(mappingVertex);
            graph[mappingVertex].push_back(i + 1);
        }
    }
    

    // loop(i, 1, totalVertices)
    // {
    //     if (graph[i].size() > 0)
    //     {
    //         print(i << "->");
    //         iteratorloop(graph[i], j)
    //         {
    //             print(val(j));
    //             space;
    //         }
    //         newline;
    //     }
    // }
    s.clear();
    print(findAnswer(graph));
    newline;
    return 0;
}