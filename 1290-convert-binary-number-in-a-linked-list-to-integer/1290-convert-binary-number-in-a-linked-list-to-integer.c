/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    struct ListNode* temp = head;
    int res = 0;

    while(temp != NULL){
        res = res | temp->val;
        res = res << 1;
        temp = temp->next;
    }

    res = res >> 1;

    return res;
}