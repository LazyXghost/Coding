#include <bits/stdc++.h>
using namespace std;

// typedef is used to give datatype a newname
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// define is used to give things an alias
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fill(start, end, val) fill(start, end, val)

#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define loopreverse(i, a, b) for (int i = a; i >= b; i--)
#define iteratorloop(v, i) for (auto i = v.begin(); i != v.end(); i++)
#define iteratorloopreverse(v, i) for (auto i = v.end() - 1; i != v.begin() - 1; i--)
#define printArray(arr, n, i)   \
    for (int i = 0; i < n; i++) \
    {                           \
        print(arr[i]);          \
        space;                  \
    }                           \
    newline;
#define inputArray(arr, n, i)   \
    for (int i = 0; i < n; i++) \
    {                           \
        input(arr[i])           \
    }
#define printVector(v, i)                       \
    for (auto i = v.begin(); i != v.end(); i++) \
    {                                           \
        print(val(i));                          \
        space;                                  \
    }                                           \
    newline;
#define inputVector(v, n, i)    \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        input(x);               \
        v.push_back(x);         \
    }
#define val(x) (*(x))

#define print(x) cout << x;
#define input(x) cin >> x;
#define space cout << " ";
#define newline cout << "\n";

const ll MOD = 1e9 + 7;

bool comparator(pii a, pii b)
{
    return (a.first < b.first);
}

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE})
// vector<int> v({SIZE OF VECTOR})

Node *reverseInSizeOfKIterative(Node *head, int k)
{
    Node *curr = head, *prevend = NULL;
    bool firstPass = true;
    while (curr != NULL)
    {
        Node *first = curr;
        Node *prev = NULL, *next = NULL;
        int count = 0;
        while (curr != NULL && count != k)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (firstPass)
        {
            head = prev;
            firstPass = false;
        }
        else
        {
            prevend->next = prev;
        }
        prevend = first;
    }
    return head;
}
Node *reverseInSizeOfK(Node *head, int k)
{
    if(head == NULL){
        return head;
    }

    Node *curr = head,*prev = NULL;
    int count = 0;
    while (curr != NULL && count != k)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    head->next = reverseInSizeOfK(curr, k);
    return prev;
}

// Append a node to the singly linked list
void Append(Node *head, int data)
{
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    Node *new_node = new Node(data);
    current->next = new_node;
}

void Display(Node *head)
{

    Node *current = head;
    while (current != NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
}

int main()
{
    FASTIO;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    Display(head);
    newline;
    int k;
    input(k);
    head = reverseInSizeOfK(head, k);
    Display(head);
    newline;
    return 0;
}