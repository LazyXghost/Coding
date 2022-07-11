#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define tests(t) ll t; cin >> t; while(t--)
#define val(x) (*(x))
#define space cout<<" ";
#define newline cout<< "\n";

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "("; _print(p.first); cerr << ","; _print(p.second); cerr << ")";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector <vector <T>> v){cerr << " => \n[\n"; for (vector<T> i : v) {cerr<<"  ";_print(i); cerr << endl;} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T> void _print(multiset <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr<< "(";_print(i.first); cerr << "--> "; _print(i.second);cerr<< "),";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr<< "(";_print(i.first); cerr << "--> "; _print(i.second);cerr<< "),";} cerr << "]";}

struct solution{
    int n;
    solution(){
        cin>>n;
        
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