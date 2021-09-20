#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

long long res(int x , int y){
    for(int i = 2;i<=x;i++){
        if(i%x == y%i){
            return i;
        }
    } 
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            cout << x << "\n";
        }
        else if (x > y)
        {
            cout << x + y << "\n";
        }
        else
        {
            if (x >= y / 2)
            {
                cout << (x + y) / 2 << "\n";
            }
            else
            {
                cout << res(x, y) << "\n";
            }
        }
    }
    return 0;
}