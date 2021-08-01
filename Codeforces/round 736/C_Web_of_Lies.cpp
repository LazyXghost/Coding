#include <bits/stdc++.h>
#define pii pair<int, int>
#define fori(s, n) for (int i = s; i < n; i++)
#define forvi(v) for (auto i = v.begin(); i != v.end(); i++)
#define val(x) (*x)
#define ll long long
#define umii unordered_map<int, int>
#define usi unordered_set<int>
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

int noOfInvulNobles(unordered_set<int> arr[], int n)
{
    unordered_set<int> st;
    int count = n;
    cout << endl;
    fori(1, n + 1)
    {
        cout << i << "-";
        for (auto j = arr[i].begin(); j != arr[i].end(); j++)
        {
            cout << (*j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    fori(1, n + 1)
    {
        bool hsf = false, hbf = false;
        for (auto j = arr[i].begin(); j != arr[i].end(); j++)
        {
            if ((*j) < i)
            {
                if (st.find((*j)) == st.end())
                {
                    hsf = true;
                }
            }
            else
            {
                hbf = true;
            }
        }
        if (hbf == true)
        {
            if (hsf == false)
            {
                st.insert(i);
                count--;
            }
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    unordered_set<int> arr[n + 1];
    fori(0, m)
    {
        int u, v;
        cin >> u >> v;
        arr[u].insert(v);
        arr[v].insert(u);
    }
    int q;
    cin >> q;
    fori(0, q)
    {
        int qc, u, v;
        cin >> qc;
        if (qc == 1)
        {
            cin >> u >> v;
            arr[u].insert(v);
            arr[v].insert(u);
        }
        else if (qc == 2)
        {
            cin >> u >> v;
            arr[u].erase(arr[u].find(v));
            arr[v].erase(arr[v].find(u));
        }
        else
        {
            cout << noOfInvulNobles(arr, n) << endl;
        }
    }

    cout << endl;
    return 0;
}