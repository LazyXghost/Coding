#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to sort the array according to frequency of elements.
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
            return a.first <= b.first;
        else
            return a.second > b.second;
    }

    vector<int> sortByFreq(int arr[], int n)
    {
        //Your code here
        vector<int> v;
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
            um[arr[i]]++;
        vector<pair<int, int>> store;
        for (auto i = um.begin(); i != um.end(); i++)
            store.push_back({(*i).first, (*i).second});
        sort(store.begin(), store.end(), comp);
        for (auto i = store.begin(); i != store.end(); i++)
        {
            int t = (*i).second;
            while (t--)
                v.push_back((*i).first);
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        int a[n + 1];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(a, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends