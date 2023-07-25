#include<bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define val(x) (*(x))
typedef long long ll;


template <typename stNode>
class SEGMENT_TREE
{
public:
    stNode neutralElement;
    virtual stNode leafElement(ll v) {}
    virtual stNode operation(stNode a, stNode b) {}

    ll size;
    vector<stNode> tree;
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (ll)a.size())
            {
                tree[x] = leafElement(a[lx]);
            }
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);

        tree[x] = operation(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = leafElement(v);
            return;
        }

        ll m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }

        tree[x] = operation(tree[2 * x + 1], tree[2 * x + 2]);
    }

    stNode query(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
            return neutralElement;
        if (lx >= l && rx <= r)
            return tree[x];
        ll m = (lx + rx) / 2;
        stNode lstq = query(l, r, 2 * x + 1, lx, m);
        stNode rstq = query(l, r, 2 * x + 2, m, rx);
        return operation(lstq, rstq);
    }

public:
    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

    void set(ll i, ll v)
    {
        set(i, v, 0, 0, size);
    }

    stNode query(ll l, ll r)
    {
        return query(l, r, 0, 0, size);
    }

    SEGMENT_TREE(ll n, stNode neutralValue)
    {
        neutralElement = neutralValue;
        size = 1;
        while (size < n)
            size *= 2;
        tree.resize(2 * size - 1, neutralElement);
    }
};

struct myStNode
{
    ll min, count;
};
class MY_SEGMENT_TREE : public SEGMENT_TREE<myStNode>
{
    /*
     * You need to implement myStNode, leafElement, operation
     */
    myStNode leafElement(ll v) override
    {
        /*
         * leafElement defines the value that should be placed at leaf node of tree, if the value v is present in array
         */
        return {v, 1};
    }
    myStNode operation(myStNode a, myStNode b) override
    {
        /*
         * Operation defines how to build the segment tree
         */
        if (a.min < b.min)
            return a;
        if (a.min > b.min)
            return b;
        return {a.min, a.count + b.count};
    }

public:
    MY_SEGMENT_TREE(ll n, myStNode neutralValue) : SEGMENT_TREE(n, neutralValue) {
        /*
         * Neutral value is the one that will be present at extra nodes
         * If array of size 6, then end nodes are 7th and 8th
         * Neutral value will fill the leaf nodes - 7,8
         */
    }
};
// Usage -: MY_SEGMENT_TREE myST(<size>, <neutralValue>);
// Example -: MY_SEGMENT_TREE minST(6, {LLONG_MAX, 0});


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
        MY_SEGMENT_TREE myST(n, {LLONG_MAX, 0});
        myST.build(arr);
        for(auto x: myST.tree){
            cout<<"{"<<x.min<<","<<x.count<<"}"<<" ";
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