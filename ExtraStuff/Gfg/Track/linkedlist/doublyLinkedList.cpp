#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

struct DoublyListNode
{
    int val;
    DoublyListNode *prev;
    DoublyListNode *next;
    DoublyListNode(int x)
    {
        val = x;
        prev = NULL;
        next = NULL;
    }
};
void traverseDoublyLinkedList(DoublyListNode *ptr)
{
    if (ptr == NULL)
    {
        cout << endl;
        return;
    }
    cout << ptr->val << " ";
    traverseDoublyLinkedList(ptr->next);
}

DoublyListNode *reverseDoublyLinkedList(DoublyListNode *head)
{
    DoublyListNode *curr = head;
    if (curr == NULL)
        return NULL;
    while (curr->next != NULL)
    {
        swap(curr->prev, curr->next);
        curr = curr->prev;
    }
    swap(curr->prev, curr->next);
    return curr;
}

int main()
{
    DoublyListNode *head = new DoublyListNode(10);
    DoublyListNode *temp1 = new DoublyListNode(20);
    DoublyListNode *temp2 = new DoublyListNode(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    head = reverseDoublyLinkedList(head);
    traverseDoublyLinkedList(head);
    return 0;
}