#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

// ================ TRAVERSAL OF LINKED LIST =====================
// --------ITERATIVE-----
void traverseLinkedList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}
// --------RECURSIVE-------
void traverseLinkedListRecursive(ListNode *ptr)
{
    if (ptr == NULL)
    {
        cout << endl;
        return;
    }
    cout << ptr->val << " ";
    traverseLinkedListRecursive(ptr->next);
}
// pointers are also passed by value
// to pass by reference do ListNode *&head
// ================================================================

// ======================= INSERTION ==============================
// ----------------- INSERT AT END ----------------------
void insertAtEnd(ListNode *head, int data)
{
    ListNode *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new ListNode(data);
}
//-------- INSERT AT GIVEN INDEX IN LINKED LIST ---------
ListNode *insertInLinkedList(ListNode *head, int data, int ind)
{
    ListNode *temp = new ListNode(data);
    if (ind == 0)
    {
        temp->next = head;
        return temp;
    }

    ListNode *currnode = head;
    int currind = -1;
    while (currnode != NULL)
    {
        currind++;
        if (ind == currind + 1)
        {
            temp->next = currnode->next;
            currnode->next = temp;
            break;
        }
        currnode = currnode->next;
    }
    return head;
}
// if we provide index greater than size of list then it dont do anything
// Size - 3 , Index available - 0,1,2,3
// ================================================================

// ======================== SEARCH ===============================
// ------- ITERATIVE ------
int searchInLinkedList(ListNode *head, int key)
{
    ListNode *curr = head;
    int ind = -1;
    while (curr != NULL)
    {
        ind++;
        if (curr->val == key)
            return ind;
        curr = curr->next;
    }
    return -1;
}
// ------- RECURSIVE ------
int searchInLinkedListRecursive(ListNode *head, int key, int ind = 0)
{
    if (head == NULL)
        return -1;
    else if (head->val == key)
        return ind;
    return searchInLinkedListRecursive(head->next, key, ind + 1);
}
// ================================================================

int main()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    traverseLinkedList(head);
    for (int i = 1; i <= 5; i += 2)
    {
        insertAtEnd(head, i);
        traverseLinkedListRecursive(head);
    }
    cout << searchInLinkedListRecursive(head, 22);
    return 0;
}