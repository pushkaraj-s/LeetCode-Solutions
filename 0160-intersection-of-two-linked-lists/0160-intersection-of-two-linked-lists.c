/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // This is the most optimized solution reffered from neetcode's YT video

    struct ListNode* tempA = headA;
    struct ListNode* tempB = headB;

    while(tempA != tempB){
        tempA = tempA ? tempA->next : headB;
        tempB = tempB ? tempB->next : headA;
    }

    return tempA;
}