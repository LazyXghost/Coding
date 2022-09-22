#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

void mzte(int a[], int n)
{
    int nz = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[nz]);
            nz++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        mzte(a, n);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}