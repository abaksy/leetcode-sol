/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdio.h>
#include<stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void moveNode(struct ListNode **sourceRef, struct ListNode **destRef)
{
    struct ListNode *newNode = *sourceRef;
    if (newNode != NULL)
    {
        *sourceRef = newNode->next;
        newNode->next = *destRef;
        *destRef = newNode;
    }
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    while (true)
    {
        if (list1 == NULL)
        {
            tail->next = list2;
            break;
        }
        else if (list2 == NULL)
        {
            tail->next = list1;
            break;
        }
        if (list1->val <= list2->val)
            moveNode(&list1, &(tail->next));
        else
            moveNode(&list2, &(tail->next));
        tail = tail->next;
    }
    return dummy.next;
}