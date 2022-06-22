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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct solution{

    void quickSortList(ListNode *head, int len){
        if(head == NULL || len == 0)
            return;

        int pivot = head->val;
        printList(head);
        cout<<"PIVOT IS ==>"<<pivot<<"\n";
        ListNode *curr = head->next, *left = head;
        int i = 1;
        int leftCount = 0;
        while(i++ < len){
            if(curr->val <= pivot){
                leftCount++;
                left = left->next;
                swap(left->val, curr->val);
            }
            curr = curr->next;
        }
        swap(head->val, left->val);
        quickSortList(head, leftCount);
        if(left->next != NULL)
            quickSortList(left->next, len - leftCount - 1);
    }

    ListNode* sortList(ListNode* A) {
        cout<<"LINKED LIST==>";
        int len = 0;
        ListNode *curr = A;
        while(curr != NULL){
            len++;
            curr = curr->next;
        }
        quickSortList(A, len);
        return A;
    }
    ll n;
    void printList(ListNode *head){
        ListNode *curr = head;
        while(curr != NULL){
            cout<<curr->val;
            space;
            curr = curr->next;
        }
        newline;
    }
    solution(){
        cin>>n;
        ListNode *head = NULL;
        ListNode *end = head;
        while(n--){
            int x;
            cin>>x;
            ListNode *tmp = new ListNode(x);
            if(head == NULL){
                head = tmp;
                end = head;
            }
            else{
                end -> next = tmp;
                end = tmp;
            }
        }
        sortList(head);
        printList(head);
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
