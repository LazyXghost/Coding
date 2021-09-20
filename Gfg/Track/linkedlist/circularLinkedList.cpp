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
ListNode *deleteHeadOfCircularLinkedList(ListNode *head)
{
    if (head == NULL)
        return NULL;
    else if (head->next == head)
    {
        delete head;
        return NULL;
    }
    head->val = head->next->val;
    ListNode *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

ListNode *deleteKthNodeInCircularLinkedList(ListNode *head, int k)
{
    if (head == NULL)
        return NULL;
    else if(head->next == head){
        delete head;
        return NULL;
    }
    else if (k == 0)
        return deleteHeadOfCircularLinkedList(head);
    
    ListNode *curr = head;
    for (int i = 0; i < k - 1; i++)
        curr = curr->next;
    ListNode *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}


void traverseCircularLinkedList(ListNode *head)
{
    ListNode *curr = head;
    cout << curr->val << " ";
    curr = curr->next;
    while (curr != head)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = head;
    traverseCircularLinkedList(head);
    cout << "Enter node index to delete" << endl;
    int k;
    cin >> k;
    head = deleteKthNodeInCircularLinkedList(head, k);
    traverseCircularLinkedList(head);
    return 0;
}