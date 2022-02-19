#include <bits/stdc++.h>
using namespace std;

// typedef gives datatype a newname
typedef long long ll;
typedef long double ld;

// define gives things an alias
#define p(a, b) pair<a, b>
#define pii pair<int, int>

#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vvpii vector<vector<pair<int, int>>>
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
#define m(a, b) map<a, b>
#define mm(a, b) multimap<a, b>
#define um(a, b) unordered_map<a, b>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define fill(start, end, val) fill(start, end, val)
#define fill(start, end, val) fill(start, end, val)
// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})

#define removeScientific cout << fixed;
#define precision(a) cout << setprecision(a);

#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b, inc) for (int i = a; i <= b; i += inc)
#define iteratorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define val(x) (*(x))

#define printArray(arr, n, i)   \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << arr[i];         \
        space;                  \
    }                           \
    newline;
#define printVector(v, i)                       \
    for (auto i = v.begin(); i != v.end(); i++) \
    {                                           \
        cout << val(i);                         \
        space;                                  \
    }                                           \
    newline;
#define space cout << " ";
#define newline cout << "\n";

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
            return res; });
    }
    void sortOnBasis(vector<int> &first, vector<int> &second)
    {
        int n = first.size();
        vector<int> indices(n), firstsorted(n), secondsorted(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int A, int B) -> bool
             {
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
            return res; });
        for (int i = 0; i < n; i++)
        {
            firstsorted[i] = first[indices[i]];
            secondsorted[i] = second[indices[i]];
        }
        first = firstsorted;
        second = secondsorted;
    }
};
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
        // unordered_map<pair<int,int>,int,HASH>mp;
    }
};
struct pqComp
{
    constexpr bool operator()(
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept
    {
        return a.second < b.second; // max heap
        // return a.second > b.second; //min heap
    }
};
bool vComp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first; // increasing order
    // return a.first > b.first; // decreasing order
}
ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        // res=(res*x)%MOD;
        y = y >> 1;
        x = x * x;
        // x = (x*x)%MOD;
    }
    return res;
}

// Implementing k stacks in array
struct kStacks
{
    /* Implement k stacks in array

    use top and next array for stacks
        arr[]    _ _ _ _ _ _ _ _  _
        next[]   1 2 3 4 5 6 7 8 -1
        freeTop=0
    for k stacks
        top[]   -1 -1 -1

    ----------SIMULATION----------
    push(100,0)
        arr[]  100 _ _ _ _ _ _ _  _
        next[]  -1 2 3 4 5 6 7 8 -1
        freeTop = 1
        top[]    0 -1 -1
    push(200,0)
        first we get freeTop index in our array as i = 1
        now we update freeTop = next[i]
        now we need to update connection in next[i] = top[sn] for stack connection
        we update top[sn] = i
        now we change arr[i] = x

        arr[]  100 200 _ _ _ _ _ _  _
        next[]  -1  0  3 4 5 6 7 8 -1
        freeTop = 2
        top[]    1 -1 -1
    push(300,0)
        arr[]  100 200 300 _ _ _ _ _  _
        next[]  -1  0   1  4 5 6 7 8 -1
        freeTop = 3
        top[]    2 -1 -1
    push(400,1)
        arr[]  100 200 300 400 _ _ _ _  _
        next[]  -1  0   1  -1  5 6 7 8 -1
        freeTop = 4
        top[]    2 3 -1
    pop(0)
        first we find index of top element of stack 0
        we get top[0] as i = 2
        then we change the top[0] = next[i] ([2])
        now we update the next element free in array as next[i] = freeTop
        we change freeTop = i also
        and at last we return arr[i]

        arr[]  100 200 -1 400 _ _ _ _  _
        next[]  -1  0   4 -1  5 6 7 8 -1
        freeTop = 2
        top[]    1 3 -1
    --------------------------------
     */
    vi arr, top, next;
    int k, freeTop, cap;
    kStacks(int k1, int n)
    {
        k = k1;
        cap = n;

        arr.resize(n);
        next.resize(n);
        top.resize(k, -1);

        freeTop = 0;
        loop(i, 0, n - 1, 1)
            next[i] = i + 1;
        next[cap - 1] = -1;
    }
    void push(int x, int sn)
    {
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }
    int pop(int sn)
    {
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeTop;
        freeTop = i;
        return arr[i];
    }
};

/* Stock span problem(Previous/next greater element-identical to stock span)
    finding all the consecutive smaller elements on left side which are less than current element
    60 10 20 40 35 30 50 70 65
    1  1  2  3  1  1  2  3  1

    There is property that span of element is
    element index - index of nearest greatest element
    so We store all greatest elements in stack

    <-60
    60 <- 10
    60 10 <- 20
    60 20 <- 40
    60 40 <- 35
    60 40 35 <- 30
    60 40 35 30 <- 50
    60 50 <- 70
    70 <- 65
    70 65
*/

struct LRA
{
    /* We can use stack data structure to find the areas

    Method-1-: Require 3 traversal and 2*n space
        find previous smaller and next smaller
        arr[]  6  2 5 4  1 5 6
        ps[]  -1 -1 1 1 -1 4 5
        ns[]   1  4 3 4  7 7 7

        and then do this
        curr+= (ns[i]-ps[i]-1)*arr[i]
        res = max(res, curr)

    Method-2-: Single traversal and n space
        we store all the element in stack such that previous element is smaller than next element

        so when we encounter greater element than top of stack we just push it in stack
        else we pop and find the area of rectangle including the popped element
            we make use of element just below it which is smaller and also element due to which it is being removed
            which will also be smaller
            currentArea will be [(index of incoming element)-(index of below element)-1]*arr[element removed]
     */

    int n;
    vi arr;
    st(int) steck;
    LRA()
    {
        cin >> n;
        loop(i, 0, n - 1, 1)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        cout << findLRA();
        newline;
    }
    int findLRA()
    {
        int res = 0,top,curr;
        loop(i, 1, n - 1, 1)
        {
            while (!steck.empty() && arr[steck.top()] >= arr[i])
            {
                top = steck.top();
                steck.pop();
                curr = arr[top] * (steck.empty() ? i : (i - steck.top() - 1));
                res = max(res, curr);
            }
            steck.push(i);
        }
        while (!steck.empty())
        {
            top = steck.top();
            steck.pop();
            curr = arr[top] * (steck.empty() ? n : (n - steck.top() - 1));
            res = max(res, curr);
        }
        return res;
    }
};