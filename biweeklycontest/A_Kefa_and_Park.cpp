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


// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})
// vector<int> v({SIZE OF VECTOR})

int findAnswer(um(int, v(int)) & tree, int cats[], int catsallowed, int m, us(int) & visited, int startingVertex = 1)
{
    if (catsallowed <= 0)
        return 0;

    int res = 0;
    bool isleaf = true;
    visited.insert(startingVertex);
    iteratorloop(tree[startingVertex], i)
    {
        if (visited.find(val(i)) == visited.end())
        {
            if (cats[startingVertex] == 1 && cats[val(i)] == 1)
                res += findAnswer(tree, cats, catsallowed - 1, m, visited, val(i));
            else
                res += findAnswer(tree, cats, m, m, visited, val(i));
            visited.insert(val(i));
            isleaf = false;
        }
    }
    if (isleaf)
        return 1;
    return res;
}

int main()
{
    FASTIO;
    int n, m;
    input(n);
    input(m);
    int cats[n + 1] = {0};
    loop(i, 1, n)
    {
        input(cats[i]);
    }
    um(int, v(int)) tree;
    loop(i, 0, n - 1)
    {
        int x, y;
        input(x);
        input(y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    // iteratorloop(tree, i)
    // {
    //     print(val(i).first << "->");
    //     iteratorloop(val(i).second, j)
    //     {
    //         print(val(j));
    //         space;
    //     }
    //     newline;
    // }
    us(int) visited;
    print(findAnswer(tree, cats, m, m, visited));
    return 0;
}