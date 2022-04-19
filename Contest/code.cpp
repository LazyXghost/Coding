#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define p(a,b) pair<a,b>
#define pii pair<int,int>
#define v(a) vector<a>
#define vi vector<int>
#define s(a) set<a>
#define ms(a) multiset<a>
#define m(a,b) map<a,b>
#define mm(a,b) multimap<a,b>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define tests(t) int t; cin >> t; while(t--)
#define loop(i, a, b, inc) for (int i = a; i <= b; i+=inc)
#define loopinv(i, a, b, dec) for (int i = a; i >= b; i-=dec)
#define iteratorloop(v, i) for(auto i = v.begin();i!=v.end();i++)
#define iteratorloopinv(v, i) for(auto i = v.rbegin();i!=v.rend();i--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define val(x) (*(x))
#define space cout<<" ";
#define newline cout<< "\n";

#define cinv(v,n) v.resize(n,0);loop(i,0,n-1,1){cin>>v[i];}
#define cin2d(v,n,m) v.resize(n,vector<long> (m,0));loop(i,0,n-1,1){loop(j,0,m-1,1){cin>>v[i][j];}}
#define pyes(CONDITION) cout << (CONDITION ? "YES" : "NO") << "\n";

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "("; _print(p.ff); cerr << ","; _print(p.ss); cerr << ")";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T> void _print(multiset <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr<< "(";_print(i.ff); cerr << "--> "; _print(i.ss);cerr<< "),";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr<< "(";_print(i.ff); cerr << "--> "; _print(i.ss);cerr<< "),";} cerr << "]";}

struct solution{
    int n;
    v(int) arr;
    solution(){
        cin>>n;
        cinv(arr,n);
        debug(arr);
        cout<<2;
        newline;
        cout<<4;
        newline;
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
    tests(t){
        solution sol;
    }
    return 0;
}
// iterators subtraction
// vector reverse iterators rbegin(), rend()
// graphs algos, segment trees
// greater, smaller comparators
// code block me daalne se format hote kya
// policy based data structures
// reverse iterator loop, cin template check


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
