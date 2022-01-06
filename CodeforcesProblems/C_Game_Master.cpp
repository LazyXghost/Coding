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
    v(p(int, int)) arr, brr;
    v(bool) winners;
    um(int, int) am, bm;
    solution()
    {
        cin >> n;
        winners.resize(n + 1, false);
        loop(i, 0, n - 1, 1)
        {
            int x;
            cin >> x;
            arr.push_back({x, i + 1});
        }
        loop(i, 0, n - 1, 1)
        {
            int x;
            cin >> x;
            brr.push_back({x, i + 1});
        }
        doPreWork();
        findAnswer();
    }
    void doPreWork(){
        sort(arr.begin(), arr.end(), comparator);
        sort(brr.begin(), brr.end(), comparator);

        loop(i, 0, n - 1, 1)
        {
            cout<<arr[i].second<<" "<<brr[i].second;
            newline;
            am.insert({arr[i].second, i});
            bm.insert({brr[i].second, i});
        }
    }
    void findAnswer(){
        int i, j;
        int p1, p2, mni, mnj;

        i = n - 1;
        p1 = arr[i].second;
        winners[p1] = true;
        mnj = bm[p1];

        j = n - 1;
        p2 = brr[j].second;
        winners[p2] = true;
        mni = am[p2];

        while (i >= mni || j >= mnj)
        {
            while (j >= mnj)
            {
                p2 = brr[j].second;
                winners[p2] = true;
                mni = min(mni, am[p2]);
                j--;
            }
            while (i >= mni)
            {
                p1 = arr[i].second;
                winners[p1] = true;
                mni = min(mni, bm[p1]);
                i--;
            }
        }

        loop(i, 1, n, 1)
        {
            cout << winners[i];
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