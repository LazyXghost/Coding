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
    void sortOnBasis(vector<int> &first, vector<int> &second)
    {
        int n = first.size();
        vector<int> indices(n), firstsorted(n), secondsorted(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int A, int B) -> bool
             {
            bool res;
            if (func == "")
                res = second[A] < second[B];
            else{
                if(func == "-")
                    res = second[A]-first[A] < second[B]-first[B];
                else if(func == "+")
                    res = second[A]+first[A] < second[B]+first[B];
                else{
                    // custom function
                    res = abs(second[A]-first[A]) < abs(second[B]-first[B]);
                }
            }
            if(order == -1)
                res = 1 - res;
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
    int n;
    v(string) arr;
    solution()
    {
        cin >> n;
        us(string) ao;
        string res = "NO";
        loop(i, 0, n - 1, 1)
        {
            string x;
            cin >> x;
            arr.push_back(x);
        }
        loop(i, 0, n - 1, 1)
        {
            string x = arr[i];
            if (checkPalindrome(x))
            {
                res = "YES";
                break;
            }
            else
            {
                cout << x << " is not a palindrome";
                newline;
            }
            if (ao.find(x) != ao.end())
            {
                res = "YES";
                break;
            }
            else
            {
                cout << x << " has not already occured";
                newline;
            }
            reverse(x.begin(), x.end());
            cout << "reversed string is " << x;
            newline;
            ao.insert(x);
        }
        cout << res;
        newline;
    }
    bool checkPalindrome(string x)
    {
        if (x.length() == 1)
        {
            return true;
        }
        else if (x.length() == 2)
        {
            return x[0] == x[1];
        }
        return x[0] == x[2];
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