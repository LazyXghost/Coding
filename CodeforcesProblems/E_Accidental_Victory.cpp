#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define p(a, b) pair<a, b>
#define v(a) vector<a>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b, inc) for (int i = a; i <= b; i += inc)
#define val(x) (*(x))

#define printVector(v, i)                       \
    for (auto i = v.begin(); i != v.end(); i++) \
    {                                           \
        cout << val(i);                         \
        space;                                  \
    }                                           \
    newline;
#define space cout << " ";
#define newline cout << "\n";


class sorting
{
    string func = "";
    int order = 1;

public:
    sorting(string a = "", int b = 1)
    {
        func = a;
        order = b;
    }
    void sortOnBasis(vector<int> &first, vector<int> &second)
    {
        int n = first.size();
        vector<int> indices(n), firstsorted(n), secondsorted(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int A, int B) -> bool
             {
            bool res;
            if (func == "")
                res = second[A] < second[B];
            else{
                if(func == "-")
                    res = second[A]-first[A] < second[B]-first[B];
                else if(func == "+")
                    res = second[A]+first[A] < second[B]+first[B];
                else{
                    // custom function
                    res = abs(second[A]-first[A]) < abs(second[B]-first[B]);
                }
            }
            if(order == -1)
                res = 1 - res;
            return res; });
        for (int i = 0; i < n; i++)
        {
            firstsorted[i] = first[indices[i]];
            secondsorted[i] = second[indices[i]];
        }
        first = firstsorted;
        second = secondsorted;
    }
};


struct solution
{
    int n, winner = -1, maxPower = INT_MIN;
    v(int) arr, players;
    v(ll) sum;
    solution()
    {
        cin >> n;
        loop(i, 0, n - 1, 1)
        {
            int x;
            cin >> x;
            arr.push_back(x);

            maxPower = max(maxPower, x);
            players.push_back(i + 1);
        }
        sorting sorter;
        sorter.sortOnBasis(players, arr);

        sum.resize(n, 0);
        sum[0] = arr[0];
        loop(i, 1, n - 1, 1)
            sum[i] = arr[i] + sum[i - 1];

        arr.clear();
        sum.clear();

        int ind = findAnswer(0, n - 1);
        v(int) winners;
        loop(i, ind, n - 1, 1)
            winners.push_back(players[i]);
        sort(winners.begin(), winners.end());

        cout << winners.size();
        newline;
        printVector(winners, i);
    }
    int findAnswer(int low, int high)
    {
        if (low > high)
            return winner;

        int mid = low + (high - low) / 2;

        if (checkIfCanWin(mid))
        {
            winner = mid;
            return findAnswer(low, mid - 1);
        }
        return findAnswer(mid + 1, high);
    }
    bool checkIfCanWin(int ind)
    {
        ll power = sum[ind];
        int checkingpower = maxPower;
        if(winner != -1){
            checkingpower = arr[winner];
        }
        if (power >= checkingpower)
            return true;
        loop(i, ind + 1, n - 1, 1)
        {
            if (power < arr[i])
                return false;
            else
            {
                power += arr[i];
                if (power >= checkingpower)
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    FASTIO;
    tests(t)
    {
        solution sol;
    }
    return 0;
}