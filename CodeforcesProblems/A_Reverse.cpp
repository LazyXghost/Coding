#include<bits/stdc++.h>
using namespace std;

// typedef gives datatype a newname
typedef long long ll;
typedef long double ld;

// define gives things an alias
#define p(a,b) pair<a,b>
#define pii pair<int,int>

#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vvpii vector<vector<pair<int,int>>>
// vector<int> v({SIZE OF VECTOR})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})

#define pqmax(a) priority_queue<a>
#define pqmin(a) priority_queue<a, vector<a>, greater<a>>
#define pqcustom(a) priority_queue<a, vector<a>, pqComp>
// by default priority queue is made max heap, to use min heap use greater or make custom comparator
// priority_queue<int> - creates max heap
// priority_queue<pair<int,int>> - ORDERING BY FIRST ELEMENT(if first elements are same then ordering by second elements)
// priority_queue<pair<int,int>,vector<pair<int,int>>,{COMPARATOR}>

#define q(a) queue<a>
#define st(a) stack<a>
#define s(a) set<a>
#define ms(a) multiset<a>
#define us(a) unordered_set<a>
#define m(a,b) map<a,b>
#define mm(a,b) multimap<a,b>
#define um(a,b) unordered_map<a,b>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define fill(start, end, val) fill(start, end, val)
#define fill(start, end, val) fill(start, end, val)
// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})

#define removeScientific cout<<fixed;
#define precision(a) cout<<setprecision(a);

#define tests(t) int t; cin >> t; while(t--)
#define loop(i, a, b, inc) for (int i = a; i <= b; i+=inc)
#define iteratorloop(v, i) for(auto i = v.begin();i!=v.end();i++)
#define val(x) (*(x))

#define printArray(arr, n, i) for(int i = 0;i<n;i++){cout<<arr[i];space;}newline;
#define printVector(v, i) for(auto i = v.begin();i!=v.end();i++){cout<<val(i);space;}newline;
#define space cout<<" ";
#define newline cout<< "\n";

const ll MOD = 1e9 + 7;
const ll INF = 1e15;

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
    void singleSort(vector<int> &first)
    {
        sort(first.begin(), first.end(), [&](int A, int B) -> bool
        {
            bool res;
            if(order == -1)
                res = A>B;
            else
                res = A<B;
            return res; 
        });
    }
    void sortOnBasis(vector<int> & first, vector<int> & second)
    {
        int n = first.size();
        vector<int> indices(n), firstsorted(n), secondsorted(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int A, int B) -> bool{
            bool res;
            if (func == ""){
                if(order == 1)
                    res = second[A] < second[B];
                else
                    res = second[A] > second[B];
            }
            else{
                if(func == "-"){
                    if(order == 1)
                        res = second[A]-first[A] < second[B]-first[B];
                    else
                        res = second[A]-first[A] > second[B]-first[B];
                }
                else if(func == "+"){
                    if(order == 1)
                        res = second[A]+first[A] < second[B]+first[B];
                    else
                        res = second[A]+first[A] > second[B]+first[B];
                }
                else{
                    if(order == 1){
                        
                    }
                    else{
                        
                    }
                    // custom function
                    // res = abs(second[A]-first[A]) < abs(second[B]-first[B]);
                }
            }
            return res;
        });
        for(int i = 0;i<n;i++){
            firstsorted[i] = first[indices[i]];
            secondsorted[i] = second[indices[i]];
        }
        first = firstsorted;
        second = secondsorted;
    }
};
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
        // unordered_map<pair<int,int>,int,HASH>mp;
    }
};
struct pqComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second < b.second; //max heap
        // return a.second > b.second; //min heap
    }
};
bool vComp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first; // increasing order
    // return a.first > b.first; // decreasing order
}
ll power(ll x,ll y){
    ll res = 1;
    while(y>0){
        if(y&1)
            res=(res*x);
            // res=(res*x)%MOD;
        y = y>>1;
        x = x*x;
        // x = (x*x)%MOD;
    }
    return res;
}

struct solution{
    int n;
    v(int) arr;
    solution(){
        cin>>n;
        loop(i,0,n-1,1)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }
        int l=-1,r=-1;
        loop(i,0,n-1,1){
            if(arr[i]!=i+1){
                l = i;
                break;
            }
        }
        loop(i,l+1,n-1,1){
            if(arr[i]==l+1){
                r = i;
                break;
            }
        }
        // cout<<"l is "<<l;
        // newline;
        // cout<<"r is "<<r;
        // newline;
        if(l!=-1)
            reverse(arr.begin()+l,arr.begin()+r+1);
        printVector(arr, i);
    }
};
int main()
{
    FASTIO;
    tests(t){
        solution sol;
    }
    return 0;
}