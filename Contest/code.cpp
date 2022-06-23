#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define p(a,b) pair<a,b>
#define pll pair<ll,ll>
#define v(a) vector<a>
#define vll vector<ll>
#define s(a) set<a>
#define ms(a) multiset<a>
#define m(a,b) map<a,b>
#define mm(a,b) multimap<a,b>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define tests(t) ll t; cin >> t; while(t--)
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

// ============================= DSU ================================

class dsu
{
    map<int,int> parent, size;

public:
    // making new set by just initialising the parent of set as the same number
    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }

    // finding the root of the set
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        // return find_set(parent[v]);

        return parent[v] = find_set(parent[v]);
        // 1st optimisization - path compression
        // directly connects all the linear chain nodes to parent
        // 7->5->3->1 ==> 7->1,5->1,3->1
    }

    // making the root of one set as the parent of root of other set will combine two sets
    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            // 2nd optimisation - union by size
            if (size[a] < size[b])
                swap(a, b);

            parent[b] = a;
            size[a] += size[b];
        }
    }

    // returning the size of the set of vertex v
    int find_size(int v)
    {
        return size[find_set(v)];
    }
};
/*
Time complexity -
                            AFTER OPTIMISATION'S
    FIND SET  - O(n)      O(alpha(n)) - almost constant
    MAKE SET  - O(1)              O(1)
    UNION SET - O(n)           O(alpha(n))
*/
//==================================================================


struct solution{
    ll n;
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
// myprettyprint.hpp
