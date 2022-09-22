#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>

using namespace std;
vector<int> printIntersection(int arr1[], int arr2[], int n, int m)
{
    //Your code here
    int i = 0, j = 0;
    vi v;
    while (i < n && j < m)
    {
        while (arr1[i] < arr2[j] && i < n)
        {
            i++;
        }
        while (arr1[i] > arr2[j] && j < m)
        {
            j++;
        }
        while (arr1[i] == arr2[j] && i < n && j < m)
        {
            if (v.size() == 0)
                v.push_back(arr1[i]);
            else
            {
                auto it = v.end();
                it--;
                if (*it != arr1[i])
                    v.push_back(arr1[i]);
            }
            i++;
            j++;
        }
        // cout<<".";
    }
    // cout<<".";
    for(auto i=v.begin();i<v.end();i++){
        cout<<*i<<" ";
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vi v = printIntersection(a, b, n, m);
    cout<<endl;
    return 0;
}


/*vector<int> printIntersection(int arr1[], int arr2[], int n, int m) 
    { 
        //Your code here
        int i = 0, j = 0;
        vector<int> v;
        // while (i < n && j < m)
        // {
        //     while (arr1[i] < arr2[j] && i < n && j < m)
        //         i++;
        //     while (arr1[i] > arr2[j] && i < n && j < m)
        //         j++;
        //     while (arr1[i] == arr2[j] && i < n && j < m)
        //     {
        //         // v.push_back(arr1[i]);
        //         i++;
        //         j++;
        //     }
        // }
        // for(int i = 0 ;i<v.size();i++)
        v.push_back(1)
        return v;
    }*/