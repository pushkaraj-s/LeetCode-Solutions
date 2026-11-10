/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    // Separate odd and Even nodes in LL
    // Solve in O(1) space and O(n) time complexity
    // We just need to change link part of Nodes
    // We will need some pointers to keep track of nodes

    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = head->next;

    while(even != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next; 
    }

    odd->next = evenHead;

    return head;    
}