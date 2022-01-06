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
#define loop(i, a, b) for (int i = a; i <= b; i++)
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

bool comparator(p(int, int) a, p(int, int) b)
{
    return (a.first < b.first);
}

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})
// vector<int> v({SIZE OF VECTOR})

struct solution
{
    int n;
    v(int) p;
    solution()
    {
        cin >> n;
        loop(i, 0, n - 1)
        {
            int x;
            cin >> x;
            p.push_back(x);
        }
        st(int) deck;
        int mx = 0;
        loop(i, 1, n - 1)
        {
            if (p[i] > p[mx])
            {
                for (int j = i - 1; j >= mx; j--)
                {
                    deck.push(p[j]);
                }
                mx = i;
            }
        }
        for(int i = n-1;i>=mx;i--){
            deck.push(p[i]);
        }
        while(!deck.empty()){
            cout<<deck.top();
            space;
            deck.pop();
        }
        newline;
    }
};

int main()
{
    FASTIO;
    tests(t)
    {
        solution sol;
    }
    return 0;
}