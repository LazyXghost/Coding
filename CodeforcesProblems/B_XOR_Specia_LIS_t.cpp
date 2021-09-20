#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

string result(int arr[], int n){
    
    return "NO";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << result(arr, n) << "\n";
    }

    return 0;
}