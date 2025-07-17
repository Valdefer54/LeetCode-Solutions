/**
 * PROBLEM: Add Two Numbers
 * URL: https://leetcode.com/problems/add-two-numbers/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* aux = malloc(sizeof(struct ListNode)); 
    aux->val= 0;
    aux->next = NULL;
    struct ListNode* current = aux;
    struct ListNode* aux1 = l1;
    struct ListNode* aux2 = l2;

  
    int  carry = 0;

    while (aux1 != NULL || aux2 != NULL || carry != 0) {
        int sum = carry;

        if (aux1 != NULL){
            sum += aux1->val;
            aux1 = aux1->next;
        }

        if (aux2 != NULL){
            sum += aux2->val;
            aux2 = aux2->next;
        }

        struct ListNode* Node = malloc(sizeof(struct ListNode)); 
        Node->val = sum % 10;
        Node->next = NULL;

        aux->next = Node;
        aux = Node;

        carry = sum /10;
        
    }
    return current->next;
}