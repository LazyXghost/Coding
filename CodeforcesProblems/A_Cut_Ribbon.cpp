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
#define forloop(i, a, b) for (int i = a; i < b; i++)
#define forloopreverse(i, a, b) for (int i = a; i > b; i--)
#define vectorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define vectorloopreverse(v, i) for (auto i = v.end() - 1; i != v.begin() - 1; i--)
#define printArray(arr, n, i)    \
    for (int i = 0; i <= n; i++) \
    {                            \
        print(arr[i]);           \
        space;                   \
    }                            \
    newline;
#define inputArray(arr, n, i)    \
    for (int i = 0; i <= n; i++) \
    {                            \
        input(arr[i])            \
    }
#define printVector(v, i)                       \
    for (auto i = v.begin(); i != v.end(); i++) \
    {                                           \
        print(val(i));                          \
        space;                                  \
    }                                           \
    newline;
#define inputVector(v, n, i)     \
    for (int i = 0; i <= n; i++) \
    {                            \
        int x;                   \
        input(x);                \
        v.push_back(x);          \
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

pair<int, bool> FindMaxPieces(int n, int values[], int valuesSize, unordered_map<int, pair<int, bool>> &Result)
{
    // first checking if result is already calculated for a no
    if (Result.find(n) != Result.end())
        return Result[n];

    if (n < values[0])
    {
        // if you can not choose any no then first store {-1,false} in map
        Result[n] = {-1, false};
        return {-1, false};
    }

    pair<int, bool> temp;

    forloop(i, 0, valuesSize)
    {

        if (n == values[i])
        {
            if (Result.find(n) == Result.end())
                Result[n] = {1, true};
            // only modify if result does not exist already
            // if we have already calculated value for particular n then that would definitely be greater than 1
            // eg we found combination 3, 3, 4
            // and current combination is 7, 3 , so we should not modify our previous result if it exist
            return Result[n];
        }
        // this equal to condition shows that you can choose only single number

        temp = FindMaxPieces(n - values[i], values, valuesSize, Result);
        // if we can not choose single then we find recursively no of pieces for n-a

        if (temp.second == true)
        {
            // if we find combination existing for n-a recursive call
            if (Result.find(n) == Result.end())
                Result[n] = {temp.first + 1, temp.second};
            // if result does not exist already then we directly assign our current value to result
            else if (temp.first + 1 > Result[n].first)
                Result[n].first = temp.first + 1;
            // otherwise we check if current value gives better result than previous
        }
    }

    return Result[n];
}
// Important test case 53 10 11 23

int main()
{
    FASTIO;
    int n;
    input(n);
    int a, b, c;
    input(a);
    input(b);
    input(c);
    int mn = min(a, min(b, c));
    int mx = max(a, max(b, c));
    int mid = a + b + c - mn - mx;
    int values[] = {mn, mid, mx};
    unordered_map<int, pair<int, bool>> Result;
    print(FindMaxPieces(n, values, 3, Result).first);
    return 0;
}