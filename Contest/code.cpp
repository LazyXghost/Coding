#include<bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define val(x) (*(x))

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

template <class T, class V> void _print(pair <T, V> p) {cerr << "("; _print(p.first); cerr << ","; _print(p.second); cerr << ")";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector <vector <T>> v){cerr << " => \n[\n"; for (vector<T> i : v) {cerr<<"  ";_print(i); cerr << endl;} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T> void _print(multiset <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr<< "(";_print(i.first); cerr << "--> "; _print(i.second);cerr<< "),";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr<< "(";_print(i.first); cerr << "--> "; _print(i.second);cerr<< "),";} cerr << "]";}

struct solution{
    long long n, k;
    vector<long long> arr;
    long long findResult(){
        long long mn = 1e9;
        for(int i = 0;i<n;i++)
            mn = min(mn, arr[i]);
        long long res = mn;
        for(int i = 0;i<n-1;i++){
            long long dis = min(arr[i], arr[i+1]);
            dis = min(dis, mn*2);
            res = max(res , dis);
        }
        return res;
    }
    solution(){
        cin>>n>>k;
        for(int i = 0;i<n;i++){
            long long x;
            cin>>x;
            arr.push_back(x);
        }
        if(n == 2){
            if(k == 2)
                cout<<1000000000<<endl;
            else if(k == 1)
                cout<<max(arr[0], arr[1])<<endl;
            else
                cout<<min(arr[0], arr[1])<<endl;
        }
        else{
            vector<pair<long long, long long>> brr;
            for(int i = 0;i<n;i++)
                brr.push_back({arr[i], i});
            sort(brr.begin(), brr.end());

            if(k == 1){
                arr[brr[0].second] = 1e9;
                cout<<findResult()<<endl;
            }
            else{
                for(int i = 0;i<k-1;i++)
                    arr[brr[i].second] = 1e9;

                long long lstind = ((brr[0].second == 0)? brr[0].second + 1: brr[0].second - 1);
                long long temp = 1e9;
                swap(arr[lstind], temp);
                long long res = findResult();
                swap(arr[lstind], temp);
                arr[brr[k-1].second] = 1e9;
                res = max(res, findResult());
                cout<<res<<endl;
            }
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
    long long t; cin >> t; while(t--){
        solution sol;
    }
    return 0;
}