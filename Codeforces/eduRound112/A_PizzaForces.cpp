#include <bits/stdc++.h>
#define pii pair<int, int>
#define fori(s, n) for (int i = s; i < n; i++)
#define forvi(v) for (auto i = v.begin(); i != v.end(); i++)
#define val(x) (*x)
#define ll long long
#define umii unordered_map<int, int>
#define usi unordered_set<int>
#define forvi(v) for (auto i = v.begin(); i != v.end(); i++)
#define takeinputarray(arr, n) \
    fori(0, n) { cin >> arr[i]; }
#define printarray(arr, n)                \
    fori(0, n) { cout << arr[i] << ' '; } \
    cout << endl;
#define takeinputvector(v, n) \
    fori(0, n)                \
    {                         \
        int x;                \
        cin >> x;             \
        v.push_back(x);       \
    }
#define printvector(v) \
    forvi(v) { cout << val(i) < ' '; }

using namespace std;

long long minutes(long long n)
{
    if(n<6){
        return 15;
    }
    long long x;
    if(n%2==0){
        x = n/2;
    }
    else
        x = (n + 1) / 2;
    x *= 5;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout<<minutes(n)<<endl;
    }

    cout << endl;
    return 0;
}