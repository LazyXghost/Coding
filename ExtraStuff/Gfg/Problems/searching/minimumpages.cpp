#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

void sag(int a[], int s[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        s[i] = sum;
    }
}
void mnmxpages(int s[], int n, int mi, int ntc, int io, int mxp, int &mnmxp)
{
    for (int i = mi; i < n - ntc + 1; i++)
    {
        int prevmxp = mxp;                                        // for every iteration mxp should remain same as the previous iteration , so storing the value of previous iteration 
        int sum;
        if (io != 0)
            sum = s[i - 1] - s[io - 1];
        else
            sum = s[i - 1];                                       // to find the sum of element between current index and old index
        mxp = max(mxp, sum);                                      // comparing to find the max page to be read by student
        if (ntc == 1)
        {
            mxp = max(mxp, s[n - 1] - s[i - 1]);                  // if last two group have to be choosen then we find the max page for this whole combination and stores value in mnmxp
            mnmxp = min(mnmxp, mxp);
        }
        else
            mnmxpages(s, n, mi + 1, ntc - 1, i, mxp, mnmxp);      // call to find the max of further remaing series
        mxp = prevmxp;                                            // mxp should be same for each iteration so giving back its value
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n], s[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sag(a, s, n);
    int k;
    cin >> k;
    int mxp = 0, mnmxp = INT_MAX;
    mnmxpages(s, n, 1, k - 1, 0, mxp, mnmxp);
    cout << mnmxp << endl;
    return 0;
}