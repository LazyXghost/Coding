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

struct item{
    long long min, count;
    void printItem(){
         cout<<min<<" "<<count<<endl;
    }
};
struct segtree{
    item NEUTRAL_ELEMENT = {INT_MAX, 0}; //sum => 0, min => +INF, max => -INF
    item LEAF_ELEMENT(long long v){
       return {v, 1};
    }
    item operation(item a,item b){
        if(a.min < b.min) return a;
        if(a.min > b.min) return b;
        return {a.min, a.count + b.count}; // sum, min, max
    }

    int size;
    vector<item> tree;
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2*size, NEUTRAL_ELEMENT);
    }

    void build(vector<long long> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)a.size()){
                tree[x] = LEAF_ELEMENT(a[lx]);
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);

        tree[x] = operation(tree[2 * x + 1],tree[2 * x + 2]);
    }
    void build(vector<long long> &a){
        build(a, 0, 0, size);
    }


    void set(int i, long long v, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x] = LEAF_ELEMENT(v);
            return;
        }

        int m = (lx+rx)/2;
        if(i < m){
            set(i, v, 2*x + 1, lx, m);
        }
        else{
            set(i, v, 2*x + 2, m , rx);
        }

        tree[x] = operation(tree[2 * x + 1],tree[2 * x + 2]);
    }
    void set(int i, long long v){
        set(i, v, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        item lstq = query(l, r, 2 * x + 1, lx, m);
        item rstq = query(l, r, 2 * x + 2, m, rx);
        return operation(lstq, rstq);
    }
    item query(int l, int r){
        return query(l, r, 0, 0, size);
    }
};


int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    segtree st;
    st.init(n);
    st.build(arr);
    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int i, v;
            cin>>i>>v;
            st.set(i,v);
        } else {
            int l, r;
            cin >> l >> r;
            st.query(l, r).printItem();
        }
    }
}