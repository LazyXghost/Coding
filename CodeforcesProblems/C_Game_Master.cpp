#include <bits/stdc++.h>
using namespace std;

// typedef is used to give datatype a newname
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

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

#define print(x) cout << x
#define input(x) cin >> x
#define space cout << " "
#define newline cout << "\n"

const ll MOD = 1e9 + 7;

bool comparator(pii a, pii b)
{
    return (a.second > b.second);
}

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})
// vector<int> v({SIZE OF VECTOR})

void findWinners(vi a, vi b, int n)
{
    char winners[n];
    loop(i, 0, n - 1)
    {
        winners[i] = '0';
    }

    if (n == 1)
    {
        winners[0] = '1';
    }
    else
    {
        unordered_set<int> alrwin;
        int curwin = -1, lstwin = -1, psize;
        auto ait = a.begin(), bit = b.begin();

        curwin = val(ait);
        winners[curwin] = '1';
        alrwin.insert(curwin);
        psize = 1;

        while (true)
        {
            while (bit != b.end() && val(bit) != curwin)
            {
                int tempwin = val(bit);
                if (alrwin.find(tempwin) == alrwin.end())
                {
                    lstwin = val(bit);
                    winners[lstwin] = '1';
                    alrwin.insert(lstwin);
                }
                bit++;
            }
            if (lstwin != -1)
                curwin = lstwin;

            while (ait != a.end() && val(ait) != curwin)
            {
                int tempwin = val(ait);
                if (alrwin.find(tempwin) == alrwin.end())
                {
                    lstwin = val(ait);
                    winners[lstwin] = '1';
                    alrwin.insert(lstwin);
                }
                ait++;
            }
            if (lstwin != -1)
                curwin = lstwin;

            if (alrwin.size() == psize)
                break;
            else
                psize = alrwin.size();
        }
    }

    loop(i, 0, n - 1)
    {
        print(winners[i]);
    }
    newline;
}

int main()
{
    FASTIO;
    tests(t)
    {
        int n;
        input(n);
        vector<pii> a, b;
        loop(i, 0, n - 1)
        {
            int x;
            input(x);
            a.push_back({i, x});
        }
        loop(i, 0, n - 1)
        {
            int x;
            input(x);
            b.push_back({i, x});
        }
        sort(a.begin(), a.end(), comparator);
        sort(b.begin(), b.end(), comparator);
        vi arr, brr;
        iteratorloop(a, i)
        {
            arr.push_back(val(i).first);
        }
        iteratorloop(b, i)
        {
            brr.push_back(val(i).first);
        }
        a.clear();
        b.clear();
        findWinners(arr, brr, n);
    }
    return 0;
}