#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define inputArray(arr, n, i)   \
    for (int i = 0; i < n; i++) \
    {                           \
        input(arr[i])           \
    }

#define print(x) cout << x;
#define input(x) cin >> x;
#define newline cout << "\n";

bool check(int sum[], int start, int end, unordered_map<int, int> &dp)
{
    if (dp.find(start) != dp.end())
    {
        int sumBet = sum[end];
        if (dp[start] >= 0)
            sumBet -= sum[dp[start]];

        if (sumBet < 0){
            dp.erase(dp.find(start));
            return false;
        }

        if (sum[end - 1] > sum[dp[start]])
            dp[start] = end - 1;
        return true;
    }

    int startingpt = end - 1;
    int sumBet = sum[end];
    if (startingpt > 0)
        sumBet -= sum[startingpt - 1];

    if (sumBet < 0)
        return false;

    dp.insert({start, startingpt - 1});
    if (startingpt == 0)
    {
        if (sum[end - 1] > 0)
            dp[start] = end - 1;
    }
    else if (sum[end - 1] > sum[dp[start]])
        dp[start] = end - 1;
    return true;
}

int findAnswer(int sum[], int n)
{
    int res = 0, lastInd = 0;
    unordered_map<int, int> dp;
    loop(i, 0, n - 1)
        if (lastInd == i || check(sum, lastInd, i, dp))
            res++;
        else
            lastInd = i + 1;
    return res;
}

int main()
{
    FASTIO;
    tests(t)
    {
        int n;
        input(n);
        int a[n];
        inputArray(a, n, i);
        int x;
        input(x);
        a[0]-=x;
        loop(i, 1, n - 1)
            a[i] = a[i] + a[i - 1] - x;
        print(findAnswer(a, n));
        newline;
    }
    return 0;
}