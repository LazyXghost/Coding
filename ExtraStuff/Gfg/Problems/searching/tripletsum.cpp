#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int i = 0, j = n - 1, k = n - 2;
    while (i < k)
    {
        if (a[i] + a[j] + a[k] == x)
        {
            cout << "Yes the pair is " << a[i] << " " << a[k] << " " << a[j] << endl;
            break;
        }
        else if (a[i] + a[j] + a[k] < x && i < k)
            while (a[i] + a[j] + a[k] < x && i < k)
            {
                i++;
            }
        else if (a[i] + a[j] + a[k] > x && i < k)
        {
            j--;
            t = j;
            k = i + 1;
            while (a[i] + a[j] + a[k] > x)
            {
                while (k < j)
                {
                    if (a[k] + a[j] == x - a[i])
                    {
                        break;
                    }
                    while (a[k] + a[j] < x - a[i] & k < j)
                    {
                        k++;
                    }
                    while (a[k] + a[j] > x - a[i] & k < j)
                    {
                        j--;
                    }
                }
            }
            if(a[i]+a[j]+a[k]!=x)
            {j=t;
            k=t-1;}
        }
    }
    if(a[i]+a[j]+a[k]!=x)
    cout<<"-1"<<endl;
    return 0;
}


/*can be done in nlogn by taking i and j in start and end and then binary searching the third element in */