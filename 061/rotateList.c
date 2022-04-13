/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
};

/*
Rotate list to the right by one node
remove the last node and insert it at the beginning
*/
void rotateOne(struct ListNode** head)
{
    struct ListNode* temp = *head;
    struct ListNode* prev = NULL;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp != *head)
    {
        temp->next = *head;
        *head = temp;
        if(prev != NULL)
            prev->next = NULL;   
    }
}

/* Return length of linked list */
int getListLen(struct ListNode** head)
{
    int len = 0;
    struct ListNode* temp = *head;
    while(temp != NULL)
    {
        len ++;
        temp = temp->next;
    }
    return len;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL)
        return head;
    int listLen = getListLen(&head);
    k = k % listLen;     // If you rotate `len` times to the right then the list doesn't change
    while(k)
    {
        rotateOne(&head);
        k--;
    }
    return head;

}