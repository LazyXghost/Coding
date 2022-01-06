#include <bits/stdc++.h>
using namespace std;

// typedef is used to give datatype a newname
typedef long long ll;
typedef long double ld;
#define INF 1e10
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
        cin >> arr[i]           \
    }
#define inputVector(v, n, i)    \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
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

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})
// vector<int> v({SIZE OF VECTOR})

int main()
{
    FASTIO;
    tests(t)
    {
        int n;
        cin >> n;
        v(int) a;
        um(int, v(int)) rep, rep2;
        loop(i, 1, n)
        {
            int x;
            cin >> x;
            a.push_back(x);
            rep[x].push_back(i);
        }

        int res = -1;
        iteratorloop(rep, i)
        {
            v(int) reps = val(i).second;
            if (reps.size() > 1)
            {
                auto k = reps.begin();
                auto j = k;
                k++;
                while(k!=reps.end()){
                    int valj= val(j), valk = val(k);
                    res = max(res, min(valj-1, valk-1)+ 1 + min(n-valj, n- valk));
                    j = k;
                    k++;
                }
            }
        }
        cout << res;
        newline;
    }
    return 0;
}