#include <bits/stdc++.h>
using namespace std;

/**
 * it is a sorter class
 * while defining you can give two variables in constructor
 *
 * First is function to sort by
 *  ""(default) - sort based on values of second vector
 *  "-" - sort by difference of two vectors
 *  "+" - sort by addition of two vectors
 *  "custom" - sort by custom function for two vectors
 *
 * Second is order to sort by
 *  1(default) - increasing
 *  -1 - decreasing
 *
 * sorting sorter;
 * sorting sorter("difference");
 * sorting sorter("difference",-1);
 */
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

bool comparator(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    vector<int> l, r;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        l.push_back(x);
        r.push_back(y);
    }
    sorting sorter;
    sorter.sortOnBasis(l, r);
    // sort(arr.begin(), arr.end(), comparator);
    for (auto v : l)
    {
        cout << v << " ";
    }
    cout << endl;
}