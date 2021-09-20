#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp.insert({s[i], i + 1});
        }
        cin >> s;
        int res = 0;
        int first = (*(mp.find(s[0]))).second;
        for (int i = 1; i < s.length(); i++)
        {
            int second = (*(mp.find(s[i]))).second;
            res += abs(second - first);
            first = second;
        }
        cout << res << "\n";
    }
    return 0;
}