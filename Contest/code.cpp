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

const int MOD = 1e9 + 7;

struct solution{
    // solution(){
    //     long long n, k;
    //     cin>>n>>k;
    //     string s;
    //     cin>>s;
    //     vector<vector<int>> dpSmall(n, vector<int>(k+1)),dpEqual(n, vector<int>(k+1)),dpBig(n, vector<int>(k+1));
    //     dpSmall[n-1][0] = s[n-1] - 'a';
    //     dpEqual[n-1][0] = 1;
    //     dpBig[n-1][1] = 26 - (s[n-1] - 'a');
    //     for(int i = n-2;i>=0;i--){
    //         for(int beauty = 0;beauty<=k;beauty++){
    //             dpSmall[i][beauty] = (s[n-1] - 'a') * (dpSmall[i+1][beauty] + dpEqual[i+1][beauty] + dpBig[i+1][beauty]);
    //             dpEqual[i][beauty] = 
    //         }
    //     }
    // }
    void changeValues(vector<int> &first, vector<int> &second, int orValue){
        for(int i = 0;i<30;i++){
            int orBit = (orValue & (1 << (29 - i)));
            if(orBit && first[i] == 0)
                second[i] = 1;
        }
    }
    int findValue(vector<int> &arr){
        int value = 0;
        for(int i = 0;i<arr.size();i++){
            value *= 2;
            if(arr[i] == 1)
                value++;
        }
        return value;
    }
    solution(){
        long long n, q;
        cin>>n>>q;
        vector<vector<int>> numbers(n+1, vector<int>(30, -1));
        map<int, vector<pair<int,int>>> mp;
        while(q--){
            int first, second, orValue;
            cin>>first>>second>>orValue;
            if(first > second)
                swap(first, second);
            mp[first].push_back({second, orValue});
            for(int i = 0;i<30;i++){
                if((orValue & (1<<(29-i))) == 0){
                    numbers[first][i] = 0;
                    numbers[second][i] = 0;
                }
            }
        }
        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<30;j++)
                if(numbers[i][j] == -1)
                    numbers[i][j] = 0;
            for(auto x: mp[i])
                changeValues(numbers[i], numbers[x.first], x.second);
        }
        for(int i = 1;i<n+1;i++)
            cout<<findValue(numbers[i])<<" ";
        cout<<endl;
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
    int t;cin>>t;while(t--)
    solution sol;
    return 0;
}