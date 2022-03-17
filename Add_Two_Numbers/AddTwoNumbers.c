/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *newNode(int val)
{
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void append(struct ListNode **head, int val)
{
    struct ListNode *newnode = newNode(val);
    if (*head == NULL)
        *head = newnode;
    else
    {
        struct ListNode *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int sum = 0;
    int carry = 0;
    int val = 0;
    struct ListNode *resultHead = NULL;
    while (l1 != NULL && l2 != NULL)
    {
        sum = l1->val + l2->val + carry;
        val = sum % 10;
        carry = sum / 10;
        append(&resultHead, val);
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 != NULL)
    {
        while (l1 != NULL)
        {
            sum = l1->val + carry;
            val = sum % 10;
            carry = sum / 10;
            append(&resultHead, val);
            l1 = l1->next;
        }
    }
    if (l2 != NULL)
    {
        while (l2 != NULL)
        {
            sum = l2->val + carry;
            val = sum % 10;
            carry = sum / 10;
            append(&resultHead, val);
            l2 = l2->next;
        }
    }
    if (carry != 0)
    {
        append(&resultHead, carry);
    }
    return resultHead;
}