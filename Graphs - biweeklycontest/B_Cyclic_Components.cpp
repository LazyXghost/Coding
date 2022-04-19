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

void eraseFrom(us(int) & a, int b)
{
    if (a.find(b) != a.end())
    {
        a.erase(a.find(b));
    }
}

int findAnswer(um(int, us(int)) graph, int vertices)
{
    int res = 0;
    us(int) notvisited;
    bool notExit;

    iteratorloop(graph, i)
        notvisited.insert(val(i).first);

    int result[vertices + 1];
    fill(result, result + vertices + 1, -1);

    while (notvisited.size() != 0)
    {
        notExit = true;

        int startingVertex = val(notvisited.begin());

        v(int) cyclic_component;
        cyclic_component.push_back(startingVertex);
        int vertex = 0;
        int i = 0;
        while (vertex != cyclic_component.size() && notExit)
        {
            // growing its cyclic component by checking all the vertices in it
            int runCount = cyclic_component.size() - 1;
            for (; i <= runCount; i++)
            {
                int vertexValue = cyclic_component[vertex];
                eraseFrom(notvisited, vertexValue);

                if (graph[vertexValue].size() != 2)
                {
                    notExit = false;
                    break;
                }
                else
                {
                    // insert connected vertex values in cyclic_component if they are not visited
                    iteratorloop(graph[vertexValue], connectedVertex)
                    {
                        int connVertexValue = val(connectedVertex);
                        if (result[connVertexValue] == 0)
                        {
                            notExit = false;
                            break;
                        }
                        if (notvisited.find(connVertexValue) != notvisited.end())
                        {
                            cyclic_component.push_back(connVertexValue);
                            eraseFrom(notvisited, connVertexValue);
                        }
                    }
                }
                vertex++;
            }
        }
        if (notExit)
        {
            iteratorloop(cyclic_component, j)
                result[val(j)] = 1;
            res++;
        }
        else
            iteratorloop(cyclic_component, j)
                result[val(j)] = 0;
    }
    return res;
}

int main()
{
    FASTIO;
    int n, m;
    input(n);
    input(m);
    um(int, us(int)) graph;
    loop(j, 0, m - 1)
    {
        int x, y;
        input(x);
        input(y);
        graph[x].insert(y);
        graph[y].insert(x);
    }
    // iteratorloop(graph, i)
    // {
    //     print(val(i).first << "->");
    //     iteratorloop(val(i).second, j)
    //     {
    //         print(val(j));
    //         space;
    //     }
    //     newline;
    // }

    print(findAnswer(graph, n));
    newline;
    return 0;
}