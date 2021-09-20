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
#define forloop(i, a, b) for (int i = a; i <= b; i++)
#define forloopreverse(i, a, b) for (int i = a; i >= b; i--)
#define vectorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define vectorloopreverse(v, i) for (auto i = v.end() - 1; i != v.begin() - 1; i--)
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

void result(int a[], int n)
{
    vector<pair<int, int>> segments;
    int segmentStart, segmentEnd;
    bool prevsegment = false;
    forloop(i, 1, n - 1)
    {
        if (a[i] < a[i - 1] && prevsegment == false)
        {
            segmentStart = i - 1;
            prevsegment = true;
        }
        else if (a[i] > a[i - 1])
        {
            if (prevsegment == true)
            {
                segmentEnd = i - 1;
                segments.push_back({segmentStart, segmentEnd});
            }
            prevsegment = false;
        }
        if (i == n - 1 && prevsegment == true)
        {
            segmentEnd = i;
            segments.push_back({segmentStart, segmentEnd});
        }
    }
    if(segments.size() == 0){
        print("yes");
        newline;
        print("1 1");
        newline;
        return;
    }
    else if (segments.size() > 1)
    {
        print("no");
        return;
    }
    vectorloop(segments, i)
        reverse(a + val(i).first, a + val(i).second + 1);

    forloop(i, 1, n-1)
    {
        if (a[i] < a[i - 1])
        {
            print("no");
            return;
        }
    }
    print("yes");
    newline;
    vectorloop(segments, i)
        print(val(i).first + 1 << " " << val(i).second + 1);
}

int main()
{
    FASTIO;
    int n;
    input(n);
    int a[n];
    forloop(i, 0, n - 1)
    {
        input(a[i]);
    }
    result(a, n);
    newline;
    return 0;
}