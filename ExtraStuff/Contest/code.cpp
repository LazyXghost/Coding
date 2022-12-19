#include<bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define val(x) (*(x))
#define ll long long

struct solution{
    ll n;
    vector<ll> arr;
    solution(){
        cin>>n;
        for(ll i = 0;i<n;i++){
            ll x;
            cin>>x;
            arr.push_back(x);
        }
        
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Debug.txt", "w", stderr);
    #endif
    FASTIO;
    ll t; cin >> t; while(t--){
        solution sol;
    }
    return 0;
}