#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define st(a) stack<a>
#define loop(i, a, b, inc) for (int i = a; i <= b; i += inc)
#define space cout << " ";
#define newline cout << "\n";

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
    /* We can use stack data structure to find the maximum areas

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

/* ----------INFIX TO POSTFIX----------
    PRECEDENCE RULE-:
        ^    HIGHEST (RTL)
        *,/          (LTR)
        +,-          (LTR)
        (,)  LOWEST
    LTR-: Associativity rule left to right, left has high precedence

    BASED ON THE FACT THAT HIGHER PRECEDENCE OPERATORS GET EVALUATED FIRST
    STACK STORAGE RULE-:
        BOTTOM(Low precedence) - TOP(Highest precedence)

    ALGO-:
        Traverse string from left to right, if x is:
            1) operand(a,b,c,d,e)-:output it.
            2) left paranthesis-:push to stack.
            3) right paranthesis-:pop until left paranthesis is found.
            4) operator-:
                if stack is empty , push x to stack else-:
                    a) if x is higher precedence than stack top push x to stack
                    b) if x is lower precedence then pop from stack until top is higher precedence or stack empty
                P.S. In case of equal precedence check associativity
        Pop everything from stack.

    Excercise -: a+b/c-d*e
 */

/* ----------INFIX TO PREFIX----------
    similar to infix to postfix
    only difference is we traverse string from right to left and we will get reversed output
    and brackets rule gets mirror imaged

    EASY METHOD -:  1)reverse string , convert postfix and then reverse it again
                    2)convert to postfix and then change using last two operands from operators like  [x y z * +]->[x *yz +]-> [+x*yz] 
    good video - watch it on gfg
 */
