#include <bits/stdc++.h>
using namespace std;

// typedef gives datatype a newname
typedef long long ll;

// define gives things an alias
typedef long double ld;
#define p(a, b) pair<a, b>
#define v(a) vector<a>
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

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})
// vector<int> v({SIZE OF VECTOR})

struct solution
{
    int n, k;
    string left, right;
    v(v(int)) graph;
    q(int) que;
    v(int) rad, par;
    bool bfsneeded = true;
    solution()
    {
        cin >> n >> k;
        graph.resize(2 * n + 1);
        cin >> left >> right;
        modelGraph();
        // printGraph();
        doBfs();
        clearSpace();
        findAnswer();
    }
    void clearSpace(){
        graph.clear();
        while(!que.empty()){
            que.pop();
        }
        rad.clear();
    }
    void findAnswer()
    {
        string res = "NO";
        if (!bfsneeded)
        {
            st(int) moves;
            int v = 0;
            while (v != -1)
            {
                moves.push(v);
                v = par[v];
            }
            int waterheight = 0;
            while (!moves.empty())
            {
                int currentheight = moves.top();
                if (currentheight > n)
                    currentheight -= n;
                moves.pop();
                if (currentheight <= waterheight)
                {
                    res = "NO";
                    break;
                }
                waterheight++;
            }
            if (moves.empty())
            {
                res = "YES";
            }
        }
        cout << res;
        newline;
    }
    void doBfs()
    {
        rad.resize(2 * n + 1, -1);
        par.resize(2 * n + 1, -1);
        que.push(1);
        rad[1] = 0;
        while (!que.empty() && bfsneeded)
        {
            int u = que.front();
            que.pop();
            iteratorloop(graph[u], i)
            {
                int v = val(i);
                if (rad[v] == -1)
                {
                    que.push(v);
                    rad[v] = rad[u] + 1;
                    par[v] = u;
                    if (v == 0)
                    {
                        bfsneeded = false;
                        break;
                    }
                }
            }
        }
    }
    void modelGraph()
    {
        loop(i, 1, n, 1)
        {
            if (left[i - 1] == '-')
            {
                if (i > n - k)
                    graph[i].push_back(0);
                else
                {
                    if (left[i] == '-')
                        graph[i].push_back(i + 1);
                    if (i>1 && left[i - 2] == '-')
                        graph[i].push_back(i - 1);
                    if (right[i + k - 1] == '-')
                        graph[i].push_back(n + i + k);
                }
            }
            if (right[i - 1] == '-')
            {
                if (i > n - k)
                    graph[n + i].push_back(0);
                else
                {
                    if (right[i] == '-')
                        graph[n + i].push_back(n + i + 1);
                    if (i>1 && right[i - 2] == '-')
                        graph[n + i].push_back(n + i - 1);
                    if (left[i + k - 1] == '-')
                        graph[n + i].push_back(i + k);
                }
            }
        }
    }
    void printGraph()
    {
        loop(u, 0, 2 * n, 1)
        {
            cout << u << "->";
            iteratorloop(graph[u], i)
            {
                int v = val(i);
                cout << v << " ";
            }
            newline;
        }
    }
};
int main()
{
    FASTIO;
    solution sol;
    return 0;
}