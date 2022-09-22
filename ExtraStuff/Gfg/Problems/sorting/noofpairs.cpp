
// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int search(int a[], int l, int h, int key)
    {
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (a[mid] == key)
            {
                return mid;
            }
            else if (a[mid] > key)
            {
                return search(a, l, mid - 1, key);
            }
            else
                return search(a, mid + 1, h, key);
        }
        return -1;
    }

    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int x[], int y[], int m, int n)
    {
        //Your code here
        sort(x, x + m);
        sort(y, y + n);
        int count = 0, append1 = 0, append2 = 0, k = 0;
        while (k < n)
        {
            if (y[k] < 2)
                append1++;
            if (y[k] < 3)
                append2++;
            if (y[k] >= 3)
                break;
            k++;
        }
        int srch;
        // cout<<append1 <<" "<<append2<<endl;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == 1)
                continue;
            else if (x[i] == 2)
            {
                srch = search(y, 0, n - 1, 5);
                if (srch != -1)
                    count += n - srch;
                count += append1;
            }
            else
            {
                srch = search(y, 0, n - 1, x[i] + 1);
                if (srch != -1)
                    count += n - srch;
                if (x[i] == 3)
                    count += append2;
                else
                    count += append1;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N;
        cin >> M >> N;
        int i, a[M], b[N];
        for (i = 0; i < M; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < N; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.countPairs(a, b, M, N) << endl;
    }
} // } Driver Code Ends